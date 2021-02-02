//
// Created by 李林 on 2021/1/17.
//

#ifndef C___SEPARATECHAININGHASHST_H
#define C___SEPARATECHAININGHASHST_H
#include<list>
template <class TYPE_KEY,class TYPE_VAL>
class SeparateChainingHashST
{
public:
    explicit SeparateChainingHashST(int M);
    ~SeparateChainingHashST();
    bool put(TYPE_KEY key, TYPE_VAL val);
    TYPE_VAL get(TYPE_KEY key);
    bool erase(TYPE_KEY key);
    void clear();
    int hashCode(TYPE_KEY);
private:
    int m_MaxLen;
    std::list<TYPE_VAL> *m_ST;
};

template<class TYPE_KEY, class TYPE_VAL>
SeparateChainingHashST<TYPE_KEY, TYPE_VAL>::SeparateChainingHashST(int M)
{
    m_ST = new std::list<TYPE_VAL>[M];
    m_MaxLen = M;
}

template<class TYPE_KEY, class TYPE_VAL>
SeparateChainingHashST<TYPE_KEY, TYPE_VAL>::~SeparateChainingHashST()
{
    delete [] m_ST;
    m_MaxLen = 0;
}

template<class TYPE_KEY, class TYPE_VAL>
bool SeparateChainingHashST<TYPE_KEY, TYPE_VAL>::put(TYPE_KEY key, TYPE_VAL val)
{
    return false;
}

#endif //C___SEPARATECHAININGHASHST_H
