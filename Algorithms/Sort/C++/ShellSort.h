//
// Created by 李林 on 2020/4/21.
//

#ifndef C___SHELLSORT_H
#define C___SHELLSORT_H

#include <iostream>
#include <vector>
#include "sort_public.h"

namespace ShellSort
{
    using std::vector;

    template <class T>
    void sort(vector<T>& a)
    {
        int Len = a.size();
        int h = 1;
        while(h < Len / 3)
        {
            h = h*3 + 1;
        }
        while(h >= 1)
        {
            for(int i = h; i < Len; i++)
            {
                for(int j = i; j >= h && a[j] < a[j-h]; j -= h)
                {
                    exch(a[j],a[j-h]);
                }
            }
            h /= 3;
        }
    }
};

#endif //C___SHELLSORT_H
