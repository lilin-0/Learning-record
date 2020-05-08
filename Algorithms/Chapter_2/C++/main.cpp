#include <iostream>
#include <vector>
#include <cstdio>
#include "SelectSort.h"
#include "InsertSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "MaxPQ.h"
using namespace std;

void PQ_TEST()
{
    MaxPQ<int> pq;
    pq.insert(4);
    pq.insert(2);
    pq.insert(5);
    pq.insert(0);
    pq.insert(6);
    for(int i = 0; i < 10; i++)
        cout<<pq.pop()<<endl;
}

int main()
{

    vector<int> x ={5,9,2,4,1,6,7,3,5,7,1,9};
    //SelectSort::sort(x);
    //InsertSort::sort(x);
    //ShellSort::sort(x);
    //MergeSort::sort(x,1);
    /*QuickSort::sort(x,1);
    for(auto a : x)
        cout<<a<<' ';
    cout<<endl;*/

    PQ_TEST();
    return 0;
}
