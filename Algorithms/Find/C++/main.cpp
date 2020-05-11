#include <iostream>
#include "SequentialSearchST.h"
using namespace std;
int main()
{
    SequentialSearchST<int,int> t;
    t.put(3,5);
    t.put(4,7);
    t.put(3,2);
    cout<<*t.get(3)<<endl;
    cout<<*t.get(4)<<endl;
    cout<<t.get(9)<<endl;
    return 0;
}
