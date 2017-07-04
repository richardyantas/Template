
template<class T>
class Node{
public:
    T data;
    Node<T> *son[2];
    Node<T> (){
        son[0] = NULL;
        son[1] = NULL;            
    }
    Node<T> (T _data){
        data = _data;
        son[0] = NULL;
        son[1] = NULL; 
    }
    Node<T> (T _data, Node<T> *_son){
        data = _data;
        son = _son;
    }
};