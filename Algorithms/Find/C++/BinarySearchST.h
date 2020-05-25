//
// Created by 李林 on 2020/5/15.
//

#ifndef C___BINARYSEARCHST_H
#define C___BINARYSEARCHST_H
#include <vector>
#include <iostream>
using namespace std;
using std::vector;

template <class KEY_TYPE, class VALUE_TYPE>
class BinarySearchST
{
public:
    struct stKey_Val
    {
        KEY_TYPE key;
        VALUE_TYPE value;
        stKey_Val() = default;
        stKey_Val(KEY_TYPE k, VALUE_TYPE v):key(k),value(v){}
    };
    BinarySearchST();
    ~BinarySearchST();
    BinarySearchST(const BinarySearchST &T) = delete;
    BinarySearchST(const BinarySearchST &&T) = delete;
    int size();
    VALUE_TYPE get(const KEY_TYPE &k);
    int rank(const KEY_TYPE &k);
    void put(const KEY_TYPE &k, const VALUE_TYPE &v);
    void remove(const KEY_TYPE &k);
private:
    int Len;
    vector<stKey_Val> data;
};

template<class KEY_TYPE, class VALUE_TYPE>
BinarySearchST<KEY_TYPE, VALUE_TYPE>::BinarySearchST()
{
    Len = 0;
    data.clear();
}

template<class KEY_TYPE, class VALUE_TYPE>
BinarySearchST<KEY_TYPE, VALUE_TYPE>::~BinarySearchST()
{
    Len = 0;
    data.clear();
}

template<class KEY_TYPE, class VALUE_TYPE>
int BinarySearchST<KEY_TYPE, VALUE_TYPE>::size()
{
    return Len;
}

template<class KEY_TYPE, class VALUE_TYPE>
VALUE_TYPE BinarySearchST<KEY_TYPE, VALUE_TYPE>::get(const KEY_TYPE &k)
{
    if(Len == 0)
        return VALUE_TYPE();
    int index = rank(k);
    cout<<"get "<<index<<' '<<data[index].value<<endl;
    if(data[index].key == k)
        return data[index].value;
    return VALUE_TYPE();
}

template<class KEY_TYPE, class VALUE_TYPE>
int BinarySearchST<KEY_TYPE, VALUE_TYPE>::rank(const KEY_TYPE &k)
{
    int iBegin = 0;
    int iEnd = Len;
    int iMid = 0;
    if(Len == 0)
        return 0;
    // 起始和结束相等时，也需要走一次循环。因为起点终点相遇时，正确位置可能在此处，也可能在后面一个
    while(iBegin <= iEnd)
    {
        iMid = (iBegin + iEnd) / 2;
        if(data[iMid].key == k)
            return iMid;
        else data[iMid].key < k ? (iBegin = iMid + 1) : (iEnd = iMid - 1);
    }
    // 循环结束，返回起点位置下标。因为在起点终点相遇的时候，正确的位置是当前位置的后一个，而在循环体中，已经对起点进行了偏移
    return iBegin;
}

template<class KEY_TYPE, class VALUE_TYPE>
void BinarySearchST<KEY_TYPE, VALUE_TYPE>::put(const KEY_TYPE &k, const VALUE_TYPE &v)
{
    int index = rank(k);
    if(index < Len && data[index].key == k)     //key已经存在，直接替换值
        data[index].value = v;
    else
    {
        cout<<"insert "<<k<<' '<<v<<endl;
        data.insert(data.begin() + index, stKey_Val(k,v));
        Len++;
    }
}

template<class KEY_TYPE, class VALUE_TYPE>
void BinarySearchST<KEY_TYPE, VALUE_TYPE>::remove(const KEY_TYPE &k)
{
    int index = rank(k);
    if(data[index].key == k)
    {
        data.erase(data.begin() + index);
        Len--;
    }
}

#endif //C___BINARYSEARCHST_H
