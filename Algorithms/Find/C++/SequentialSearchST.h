//
// Created by 李林 on 2020/5/11.
// 基于链表的顺序查找符号表

#ifndef C___SEQUENTIALSEARCHST_H
#define C___SEQUENTIALSEARCHST_H

#include<iostream>
using std::shared_ptr;
using std::make_shared;

template <class TYPE_KEY, class TYPE_VAL>
class SequentialSearchST
{
private:
    class Node          // 节点存储结构
    {
    public:
        TYPE_KEY key;
        TYPE_VAL val;
        shared_ptr<Node> next;
        Node():key(),val(),next(nullptr) {}
        Node(TYPE_KEY k, TYPE_VAL v):key(k),val(v),next(nullptr){}
    };

    shared_ptr<Node> Header;
public:
    SequentialSearchST();
    void put(const TYPE_KEY &key, const TYPE_VAL &val);
    TYPE_VAL* get(TYPE_KEY key);
};

template<class TYPE_KEY, class TYPE_VAL>
SequentialSearchST<TYPE_KEY, TYPE_VAL>::SequentialSearchST()
{
    Header = make_shared<Node>();
}

template<class TYPE_KEY, class TYPE_VAL>
TYPE_VAL* SequentialSearchST<TYPE_KEY, TYPE_VAL>::get(TYPE_KEY key)
{
    for(auto x = Header; x != nullptr; x = x->next)
    {
        if(key == x->key)
            return &x->val;
    }
    return nullptr;
}

template<class TYPE_KEY, class TYPE_VAL>
void SequentialSearchST<TYPE_KEY, TYPE_VAL>::put(const TYPE_KEY &key, const TYPE_VAL &val)
{
    auto temp_ptr = get(key);       // 先查找，找到直接修改，没找到插入一条数据
    if(temp_ptr != nullptr)
    {
        *temp_ptr = val;
    }
    else
    {
        auto ptr = Header;
        Header = make_shared<Node>(key,val);
        Header->next = ptr;
    }
}



#endif //C___SEQUENTIALSEARCHST_H
