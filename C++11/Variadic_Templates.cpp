/*
 * @Author: your name
 * @Date: 2021-04-22 21:51:17
 * @LastEditTime: 2021-04-22 21:57:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++11/Variadic_Templates.cpp
 */

#include<iostream>
using namespace std;
void print()
{}
template <typename T,typename... Types>
void print(const T& firstArg,const Types&... args)
{
    cout << firstArg << endl;
    print(args...);
}

int main()
{
    print(1, 2, 3, "xxx", bitset<16>(377), 99);
    cout << "c++" << __cplusplus << endl;
    return 0;
}