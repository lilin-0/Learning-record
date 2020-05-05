//
// Created by 李林 on 2020/4/30.
//

#ifndef C___QUICKSORT_H
#define C___QUICKSORT_H

#include <vector>
#include "sort_public.h"

namespace QuickSort
{
    using std::vector;

    template <class T>
    int partition(vector<T> &arr, int iBegin, int iEnd)
    {
        int i = iBegin, j = iEnd + 1;
        T Tval = arr[i];
        while(1)
        {
            while(arr[++i] < Tval)
            {
                if(i == iEnd)
                    break;
            }
            while(Tval < arr[--j])
            {
                if(j == iBegin)
                    break;
            }
            if(i >= j)
                break;
            exch(arr[i],arr[j]);
        }
        exch(arr[iBegin],arr[j]);
        return j;
    }

    template <class T>
    void sort(vector<T> &arr, int iBegin, int iEnd)
    {
        if(iBegin >= iEnd)
            return;
        int j = partition(arr,iBegin,iEnd);
        sort(arr, iBegin, j - 1);
        sort(arr, j + 1, iEnd);
    }

    template <class T>
    void sort(vector<T> &arr)
    {
        sort(arr, 0, arr.size() - 1);
    }


}


#endif //C___QUICKSORT_H
