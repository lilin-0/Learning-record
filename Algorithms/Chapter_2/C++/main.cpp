#include <iostream>
#include <vector>
#include <cstdio>
#include "SelectSort.h"
#include "InsertSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
using namespace std;
int main()
{

    vector<int> x ={5,9,2,4,1,6,7,3,5,7,1,9};
    //SelectSort::sort(x);
    //InsertSort::sort(x);
    //ShellSort::sort(x);
    //MergeSort::sort(x,1);
    QuickSort::sort(x,1);
    for(auto a : x)
        cout<<a<<' ';
    cout<<endl;

    return 0;
}
