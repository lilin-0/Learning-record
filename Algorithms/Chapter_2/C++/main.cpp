#include <iostream>
#include <vector>
#include "SelectSort.h"
#include "InsertSort.h"
using namespace std;
int main()
{
    std::cout << "Hello, World!" << std::endl;

    vector<int> x ={5,9,2,4,1,6,7,3,5,7,1,9};
    //SelectSort::sort(x);
    InsertSort(x);
    for(auto a : x)
        cout<<a<<' ';
    cout<<endl;
    return 0;
}
