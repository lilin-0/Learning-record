#include <iostream>
#include <vector>
#include <cstdio>
#include "SelectSort.h"
#include "InsertSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "MaxPQ.h"
#include "HeapSort.h"
using namespace std;

void PQ_TEST()
{
    MaxPQ<int> pq;
    pq.insert(4);
    pq.insert(2);
    pq.insert(5);
    cout<<pq.pop()<<endl;
    cout<<pq.pop()<<endl;
    cout<<"AAAAAAAAAAAAAAAAA"<<endl;
    pq.insert(0);
    pq.insert(6);
    for(int i = 0; i < 10; i++)
        cout<<pq.pop()<<endl;
}


void HEAPSORT_TEST()
{
    vector<int> test = {3,4,2,1,7,5,8,2,5,8,8};
    HeapSort::sort(test);
    for(auto x : test)
        cout<<x<<' ';
    cout<<endl;
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

    //PQ_TEST();
    HEAPSORT_TEST();
    return 0;
}
