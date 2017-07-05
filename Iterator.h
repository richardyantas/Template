#include "Node.h"
#include <utility>

#define status second
#define node first

template<class T>
class CIterator_inorder{
    
public:
    std::stack< std::pair<Node<T>*,T> > st;
    
    CIterator_inorder(){}
    
    CIterator_inorder(Node<T>* p){}
        
    void operator = (CIterator_inorder<T> i)
    {  
        st = i.st;
    }
    
    bool operator != (CIterator_inorder<T> i)
    {
        return !st.empty();
    }
    
    T operator *()
    {
        return st.top().ptr->data;
    }
        
    CIterator_inorder<T> operator ++(int) //  int ???
    {
        
        bool flag=false;
        while( !st.empty() && !flag )
        {
            if( st.top().status == 0 )
                {
                st.top().status=1;
                if(st.top().node->son[0])
                {                
                    st.push( make_pair( st.top().node,0 ) );                
                }
            }
            else if(st.top().status==1)
            {
                st.top().status=2;
                flag = true;
            }
            else if(st.top().status==2)
            {
                Node<T>* temp = st.top().node;
                st.pop();
                if(temp->son[1])
                {           
                    st.push( make_pair( temp.top().node, 0 ) );
                }
            }
            
        }
        return *this;  //  this ??? 
        
    }    
};



template<class T>
class CIterator_preorder{
    
public:
    std::stack< std::pair< Node<T>*,T> > st;
    
    CIterator_preorder(){}

    CIterator_preorder(Node<T>* p){}
        
    void operator = (CIterator_preorder<T> i)
    {  
        st = i.st;
    }
    
    bool operator != (CIterator_preorder<T> i)
    {
        return !st.empty();
    }
    
    T operator *()
    {
        return st.top().node->data;
    }
    
    CIterator_preorder<T> operator ++(int) 
    {
        
        bool flag = false;
        
        while( !st.empty() && !flag )
        {
            std::pair< Node<T>*,T > p = st.top(); 
            switch( p.status )                                                                                    
            {
                case 0:
               
                    st.top().status = 1;
                    
                    if(p.ptr->son[0])
                    {                        
                        p.ptr = p.ptr->son[0];
                        p.status = 0;
                        st.push(p);
                        flag = true;
                    }                                
                    break;                               
                case 1:
                          
                    st.top().status = 2;
                    
                    if(p.ptr->s[1])
                    { 
                        p.ptr = p.ptr->son[1];
                        p.status = 0;
                        st.push(p);
                        flag = true;                        
                    }                    
                    break;
                case 2:
                    st.pop();
                    break;
                    
            }
        }        
        return *this;      
    }        
};





template<class T>
class CIterator_postorder{
    
public:
    std::stack< std::pair< Node<T>*, T > > st;
    
    CIterator_postorder(){
    }

    CIterator_postorder(Node<T>* p){}
        
    void operator = (CIterator_postorder<T> i)
    {  
        st = i.st;
    }
    
    bool operator != (CIterator_postorder<T> i)
    {
        return !st.empty();
    }
    
    T operator *()
    {
        return st.top().node->data;
    }
    
    CIterator_postorder<T> operator ++(int) 
    {
        
        while(!st.empty())
        {
            Node<T>* p = st.top().node;
             
            if( st.top().status == 0 )
            {   
                st.top().status ++;
                if( p->son[0])
                {
                    p = p->son[0];
                    st.push( std::make_pair(p,0) );
                }                                                                                                                            
            }            
            else if( st.top().status == 2)
            {        
                st.top().status ++;
                if(p->son[1])
                {
                    p = p->son[1];  
                    st.push( std::make_pair(p,0) );
                }                        
            }            
            else if( st.top().status == 1)                
            {
                st.top().status ++;                                                        
                return *this;
            }       
            else if( st.top().status == 3 )
            {
                st.pop();                  
            }
        }
        return *this;  
        
    }  
};
        
    