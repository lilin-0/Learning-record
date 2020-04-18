//
// Created by 李林 on 2020/4/18.
//

#ifndef C___INSERTSORT_H
#define C___INSERTSORT_H

#include <iostream>
#include <vector>
using namespace std;

void exch(int &a, int &b)
{
    a ^= b ^= a ^= b;
}

void InsertSort(vector<int> & arr)
{
    for(int i = 1; i < arr.size(); i++)
    {
        for(int j = i; j >= 0; j--)
        {
            if(arr[j] < arr[j-1])
            {
                exch(arr[j],arr[j-1]);
            }
        }
    }
}
#endif //C___INSERTSORT_H
