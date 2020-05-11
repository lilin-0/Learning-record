//
// Created by 李林 on 2020/5/7.
//

#ifndef C___MAXPQ_H
#define C___MAXPQ_H

#include <vector>

using std::vector;
#define PQ_ERR 0x7fffffff

/* T结构需要有<运算符 */
template <class T>
class MaxPQ
{
private:
    vector<T> pq;
    void swim(int x);
    void sink(int x);
    void swap(int x, int y);
    int Len;
public:
    MaxPQ();
    void insert(T Key);
    T pop();
    int GetLen();
};

template<class T>
MaxPQ<T>::MaxPQ()
{
    pq.emplace_back(T());   //构造函数将下标0位置填充一个空闲元素，真正存储时从1位置开始
    Len = 0;
}

template <class T>
void MaxPQ<T>::insert(T Key)
{
    pq.emplace_back(Key);
    Len++;
    swim(GetLen());         //插入元素后，从末尾开始上浮
}

template<class T>
T MaxPQ<T>::pop()
{
    if(GetLen() == 0)
        return PQ_ERR;
    T Ret = pq[1];
    swap(1,Len);
    pq.pop_back();
    Len--;
    sink(1);    //下沉
    return Ret;
}

template<class T>
int MaxPQ<T>::GetLen()
{
    return Len;
}
template<class T>
void MaxPQ<T>::swim(int x)
{
    while(x > 1 && pq[x/2] < pq[x])     //父节点要小于子节点才需要上浮
    {
        swap(x/2,x);
        x /= 2;
    }
}

template<class T>
void MaxPQ<T>::sink(int x)
{
    while(x * 2 <= Len)     //保证子节点不越界
    {
        int child = x * 2;
        if(child + 1 <= Len && pq[child] < pq[child+1])     //从两个子节点中找到较大的一个
            child++;
        if(pq[x] < pq[child])
            swap(x,child);
        else
            break;
    }
}

template<class T>
void MaxPQ<T>::swap(int x, int y)
{
    T temp = pq[x];
    pq[x] = pq[y];
    pq[y] = temp;
}


#endif //C___MAXPQ_H
