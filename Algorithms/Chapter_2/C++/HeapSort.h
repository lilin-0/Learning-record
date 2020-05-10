//
// Created by 李林 on 2020/5/10.
//

#ifndef C___HEAPSORT_H
#define C___HEAPSORT_H

#include <vector>
#include "sort_public.h"
namespace HeapSort
{
    using std::vector;

    template <class T>
    void sink(vector<T> &arr, int iNode, int iMax)
    {
        while(iNode * 2 <= iMax)    //判断当前节点是否有子节点
        {
            int iChild = iNode * 2;
            if(iChild + 1 <= iMax && arr[iChild] < arr[iChild + 1])     //当前节点拥有两个子节点的时候，取子节点值较大的一个
                iChild++;
            if(arr[iChild] < arr[iNode])        //子节点比当前节点大，则需要下沉 反之已经具有堆特性，结束下沉
                break;
            exch(arr[iChild], arr[iNode]);
            iNode = iChild;         //下沉交换之后，以当前子节点继续迭代实现堆特性
        }
    }

    template <class T>
    void sort(vector<T> &arr)
    {
        arr.insert(arr.begin(),T());        //为适应数组实现堆的特性，起始位置插入一个不需要的数据
        int Len = arr.size() - 1;
        for(int i = Len/2; i > 0; i--)      //从有子节点的位置开始，使得数据具有堆得特性
            sink(arr,i,Len);
        while(Len > 1)
        {
            exch(arr[1],arr[Len--]);        //堆中第一个元素是最大值，放入最后一个位置，放入之后，缩小未排序的范围
            sink(arr,1,Len);
        }
        arr.erase(arr.begin());
    }
};
#endif //C___HEAPSORT_H
