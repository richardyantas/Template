#include "Iterator.h"
#include <stack>

template<class T>
class Tree{
    
    typedef CIterator_inorder<T> Iterator_inorder;
    typedef CIterator_preorder<T> Iterator_preorder;
    typedef CIterator_postorder<T> Iterator_postorder;
    
public:

    Node<T> *root;
    Tree()
    {
        root = NULL;
    }
    
    bool find(T x, Node<T>** &p)
    {
        for( p = &root; (*p && ( (*p) -> data != x) ); p = &( (*p) -> son[( (*p) -> data) < x] )){};
        return !!(*p);        
    } 
       
    bool insert(T x)
    {
        Node<T> **p;
        if( find(x,p) )return false;
        *p = new Node<T> (x);
        return true;
    }
    
    bool remove(T x)
    {
        Node<T> **p;
        if( !find(x,p) )return false; 
        
        if((*p)->son[0] && (*p)->son[1])
        {
            Node<T> **q;
            for( q=&((*q)->son[1]);(*q)->son[0]; q=&((*q)->son[0]) ){};
            (*p)->dat=(*q)->dat;
            p=q;
        }
        
        Node<T> *t=*p;
        *p=(*p)->son[!((*p)->son[0])];
        delete t;
        return true;      
    }
    
    Iterator_inorder begin_in_order()
    {
        
        Iterator_inorder ret;
        Node<T>* r=root;
        pair<T> pi(r,0);        
        ret.st.push(pi);
        r = r->son[0];
        
        while(r)
        {
            ret.st.top().status = 1;
            pair<T> ps(r,0);
            ret.st.push(ps);
            r=r->son[0];
        }
        
        ret.st.top().status = 2;
        return ret;
    }
    
    Iterator_inorder end_in_order()
    {
        Iterator_inorder x;
        return x;
    }
    
    
    Iterator_preorder begin_pre_order()
    {        
        Iterator_preorder ret;
        Node<T>* r=root;
        pair<T> pi(r,0);
        ret.st.push(pi);        
        return ret;
    }
    
    Iterator_preorder end_pre_order()
    {
        Iterator_preorder x;
        return x;
    }
    
    Iterator_postorder begin_post_order()
    {        
        Iterator_postorder ret;
        Node<T>* r=root;
        
        ret.stt.push(r); 
        
        while( r->son[0] ){
          r=r->son[0];
          ret.stt.push(r);    
        }
        // for ()  Doesnt works
    
        if(r->son[1]){
            ret.stt.push(r->son[1]);
        }
               
        return ret;
    }
    
    Iterator_postorder end_post_order()
    {
        Iterator_postorder x;
        return x;
    }
    
    void preorder();
    
};



template<class T>
void Tree<T>::preorder() 
{
    std::stack< Node<T>*  > st;
    st.push(root);
    
    while( !st.empty() )
    {
        Node<T>* t = st.top();
        std::cout << t->data << std::endl;
        st.pop();
        if(t->son[1])
            st.push( t->son[1] );
        
        if(t->s[0])
            st.push( t->son[0] );            
    }
  
    
}  