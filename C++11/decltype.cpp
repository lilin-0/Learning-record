/*
 * @Author: your name
 * @Date: 2021-05-08 20:24:28
 * @LastEditTime: 2021-05-08 20:35:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++11/decltype.cpp
 */
#include <iostream>
#include <map>
using namespace std;

template <typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y)     //编译器推导类型
{
    return x + y;
}

int main()
{
    cout << add(1, 2) << endl;
    map<int, int> obj;
    decltype(obj)::value_type obj2;
    return 0;
}