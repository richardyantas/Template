#include "Node.h"

template<typename T>
struct pair
{
    Node<T>* ptr;
    int status;    
    pair(Node<T>* _ptr,int _status)
    {
            ptr = _ptr;
            status = _status;
    }    
};

template<class T>
class CIterator_inorder{
    
public:
    std::stack< pair<T> > st;
    std::stack< Node<T>* > stt;
    
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
                if(st.top().ptr->son[0])
                    {
                    pair<T> t(st.top().ptr->son[0],0);
                    st.push(t);
                    
                }
            }
            else if(st.top().status==1)
            {
                st.top().status=2;
                flag = true;
            }
            else if(st.top().status==2)
            {
                Node<T>* temp = st.top().ptr;
                st.pop();
                if(temp->son[1])
                {
                    pair<T> t(temp->son[1],0);
                    st.push(t);
                }
            }
            
        }
        return *this;  //  this ??? 
        
    }    
};



template<class T>
class CIterator_preorder{
    
public:
    std::stack< pair<T> > st;
    
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
        return st.top().ptr->data;
    }
    
    CIterator_preorder<T> operator ++(int) 
    {
        
        bool flag = false;
        
        while( !st.empty() && !flag )
        {
            pair<T> p = st.top(); 

            //std::cout << p.ptr->data <<  " " << p.status  << std::endl;
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
    std::stack< Node<T>* > stt;
    
    CIterator_postorder(){
    }

    CIterator_postorder(Node<T>* p){}
        
    void operator = (CIterator_postorder<T> i)
    {  
        stt = i.stt;
    }
    
    bool operator != (CIterator_postorder<T> i)
    {
        return !stt.empty();
    }
    
    T operator *()
    {
        return stt.top()->data;
    }
    
    CIterator_postorder<T> operator ++(int) 
    {
        
        while(!stt.empty())
        {
            Node<T>* p = stt.top();            
            
            if(p->son[0])
            { 
                p = p->son[0];
                stt.push(p);                                                                                  
            }            
            else if(p->son[1])
            {              
                p = p->son[1];  
                stt.push(p);            
            }            
            else
            {
                stt.pop();                
                break;
            }            
        }
        std::cout << "inside" << std::endl;
        return *this;  
        
    }  
};
        
    