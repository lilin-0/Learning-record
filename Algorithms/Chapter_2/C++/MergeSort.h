//
// Created by 李林 on 2020/4/23.
//

#ifndef C___MERGESORT_H
#define C___MERGESORT_H

#include <vector>
#include <iostream>

namespace MergeSort
{
    using std::vector;

    template <class T>
    bool min(T a,T b);

    template <class T>
    void merge(vector<T> &a, int ibegin, int imid, int iend)
    {
        vector<T> temp = a;       // 此处每次合并都需要构造对象，性能不高
        int i = ibegin;
        int j = imid+1;
        for(int w = ibegin; w <= iend; w++)
        {
            if(i > imid)
            {
                a[w] = temp[j++];
            }
            else if(j > iend)
            {
                a[w] = temp[i++];
            }
            else if(temp[i] < temp[j])
            {
                a[w] = temp[i++];
            }
            else
            {
                a[w] = temp[j++];
            }
        }
    }
    template <class T>
    void sort(vector<T> &a, int ibegin, int iend)
    {
        if(ibegin >= iend)
            return;
        int imid = (ibegin + iend) / 2;
        sort(a,ibegin,imid);
        sort(a,imid + 1,iend);
        merge(a,ibegin,imid,iend);
    }

    int getmin(int a,int b)
    {
        return a>b?b:a;
    }

    template <class T>
    void sortBU(vector<T> &arr, int ibegin, int iend)
    {
        for(int i = ibegin+1; i < iend+1; i += i)
        {
            for(int j = 0; j < iend - i + 1; j += i+i)
                merge(arr,j,i+j-1,getmin(i+i+j-1,iend));
        }
    }

    template <class T>
    void sort(vector<T> &arr, int flag = 0)
    {
        if(flag == 1)
            sortBU(arr, 0, arr.size() - 1);
        else
            sort(arr, 0, arr.size() - 1);
    }
}



#endif //C___MERGESORT_H
