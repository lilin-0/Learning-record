//
// Created by 李林 on 2020/4/23.
//

#ifndef C___MERGESORT_H
#define C___MERGESORT_H

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, int ibegin, int imid, int iend)
{
    vector<int> temp = a;       // 此处每次合并都需要构造对象，性能不高
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
    cout<<endl;
}

void mergesort(vector<int> &a, int ibegin, int iend)
{
    if(ibegin >= iend)
        return;
    int imid = (ibegin + iend) / 2;
    cout<<ibegin<<' '<<iend<<' '<<imid<<endl;
    mergesort(a,ibegin,imid);
    mergesort(a,imid + 1,iend);
    merge(a,ibegin,imid,iend);
}
int min(int a,int b)
{
    return a>b?b:a;
}
void mergesortBU(vector<int> &arr, int ibegin, int iend)
{
    for(int i = 1; i < arr.size(); i += i)
    {
        for(int j = 0; j < arr.size() - i; j += i+i)
            merge(arr,i,i+j-1,min(i+i+j-1,arr.size()-1));
    }
}
#endif //C___MERGESORT_H
