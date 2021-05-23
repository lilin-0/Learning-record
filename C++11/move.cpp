/*
 * @Author: your name
 * @Date: 2021-05-23 09:18:41
 * @LastEditTime: 2021-05-23 09:24:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++11/move.cpp
 */

#include<iostream>
using namespace std;
void process(int &x)
{
    cout << "process & " << x << endl;
}
void process(int &&x)
{
    cout << "process && " << x << endl;
}
void forwad(int &&x)
{
    cout << "forwad && ";
    //这里的右值引用，调用process的时候，会自动变成左值引用
    process(x);
}
void forwad(int &x)
{
    cout << "forwad & ";
    process(x);
}
int main()
{
    forwad(2);      // forwad &&  -> process &
    int a = 3;  
    forwad(a);      // forwad &  -> process &
    return 0;
}