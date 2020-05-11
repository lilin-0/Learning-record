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

    //三向切分快速排序
    template <class T>
    void sort3way(vector<T> &arr, int iBegin, int iEnd)
    {
        /*
         * iBegin - lt 之间为小于切分元素的数据
         * lt - i之间为等于切分元素的数据
         * i - gt之间为待计算的数据
         * |     <v      |  =v  |*****|      >v
         * iBegin        lt     i     gt            iEnd
         * */

        if(iBegin >= iEnd)          //递归退出
            return;
        int lt = iBegin, gt = iEnd, i = iBegin + 1;
        T Tval = arr[iBegin];       //切分元素
        while(i <= gt)
        {
            if(arr[i] < Tval)       //小于切分元素
                exch(arr[i++], arr[lt++]);
            else if(arr[i] > Tval)  //大于切分元素
                exch(arr[i],arr[gt--]);
            else                    //i位置元素等于切分元素
                i++;
        }
        /* a[iBegin...lt-1] < v = a[lt...gt] < a[gt+1 ... iEnd] */
        sort3way(arr, iBegin, lt - 1);
        sort3way(arr, gt+1, iEnd);
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
    void sort(vector<T> &arr,int flag = 0)
    {
        if(flag == 0)
            sort(arr, 0, arr.size() - 1);
        else
            sort3way(arr, 0, arr.size() - 1);
    }


}


#endif //C___QUICKSORT_H
