/*
 * @Author: your name
 * @Date: 2021-05-07 21:17:11
 * @LastEditTime: 2021-05-07 21:41:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++11/Alias.cpp
 */

#include<iostream>
#include<vector>
using namespace std;

template <typename T>
using Vec = vector<T>;

template<typename Container>
void test(Container x)
{
    // 取出容器值类型
    typedef typename iterator_traits<typename Container::iterator>::value_type ValType;
    cout << *x.begin() << endl;
    cout << "test:" << ValType() << endl;
}

int main()
{
    Vec<int> x;
    x.push_back(3);
    cout << x[0] << endl;
    test(x);
    return 0;
}
