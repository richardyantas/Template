#include <iostream>
#include <utility>
#include <map>
#include <stack>
#include "Tree.h"

using namespace std;

int main(){
    Tree<float> t;
    
    t.insert(3);
    t.insert(2);
    t.insert(4);
    t.insert(1);
    t.insert(1.5);
    
    CIterator_postorder<float> i;
    i=t.begin_post_order();
    
    
    for(i=t.begin_post_order(); i!=t.end_post_order(); i++)
    {
        cout << *i << endl; 
        cin.get();
    }
       
    
    cout << "-------------------" << endl;
    
    //t.preorder();
	return 0;
}
