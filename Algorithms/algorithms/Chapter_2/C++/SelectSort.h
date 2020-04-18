//
// Created by 李林 on 2020/4/16.
//

#ifndef C___SELECTSORT_H
#define C___SELECTSORT_H

#include <vector>
using namespace std;
class SelectSort
{
public:
    static void sort(vector<int> & a);
    static void exch(int &x,int &y);
};

void SelectSort::exch(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

void SelectSort::sort(vector<int> & a)
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

#endif //C___SELECTSORT_H
