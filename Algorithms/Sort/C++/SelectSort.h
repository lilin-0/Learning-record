//
// Created by 李林 on 2020/4/16.
//

#ifndef C___SELECTSORT_H
#define C___SELECTSORT_H

#include <vector>
#include "sort_public.h"

namespace SelectSort
{
    using std::vector;

    template <class T>
    void sort(vector<T> & a)
    {
        for(int i = 0; i < a.size(); i++)
        {
            int min = i;
            for(int j = i + 1; j < a.size(); j++)
            {
                if(a[min] > a[j])
                {
                    min = j;
                }
            }
            exch(a[i],a[min]);
        }
    }
};


#endif //C___SELECTSORT_H
