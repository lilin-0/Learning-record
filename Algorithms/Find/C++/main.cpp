#include <iostream>
#include <map>
#include <vector>
#include "SequentialSearchST.h"
#include "BinarySearchST.h"
#include "BST_base.h"
using namespace std;

void test_binarySearchST()
{
    BinarySearchST<int,int> ST;
    ST.put(1,1);
    ST.put(2,2);
    cout<<ST.get(1)<<endl;
    cout<<ST.get(2)<<endl;
}

void test_BST()
{
    BST_base<int,string> bst;
    bst.put(1,"AAA");
    bst.put(2,"bbb");
    bst.put(5,"eee");
    bst.put(4,"ddd");
    bst.put(3,"ccc");
    cout<<bst.minKey()<<endl;
    cout<<bst.maxKey()<<endl;
    bst.put(3,"333");

    cout<<bst.get(bst.minKey())<<endl;
    bst.deleteKey(5);
    //bst.deleteMinKey();
    cout<<"select:"<<bst.size()<<endl;
    for(int i = 0; i < bst.size(); i++)
        cout<<bst.select(i)<<endl;

    cout<<bst.get(bst.floor(5));
}

int main()
{
    test_BST();
    //test_binarySearchST();
    return 0;
}
