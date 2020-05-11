#include <iostream>
#include <queue>
#include "Queue.h"
#include "UF.h"

using namespace std;
void test_UF();

int main()
{
    test_UF();
    return 0;
}

void test_queue()
{
    Queue<int> t;
    t.push(33);
    t.push(22);
    t.push(11);
    int w;
    cout<<t.pop(w)<<' '<<w<<endl;
    cout<<t.pop(w)<<' '<<w<<endl;
    cout<<t.pop(w)<<' '<<w<<endl;
    cout<<t.pop(w)<<' '<<w<<endl;
    t.push(332);
    cout<<t.pop(w)<<' '<<w<<endl;
    std::cout << "Hello, World!" << std::endl;
}
void test_UF()
{
    UF test(10);
    int a,b;
    while(cin>>a>>b)
        test.quick_union(a,b);
    for(int i = 0; i < 10; i++)
        cout<<test.find(i)<<endl;
}