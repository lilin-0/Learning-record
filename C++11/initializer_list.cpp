/*
 * @Author: your name
 * @Date: 2021-04-26 21:29:53
 * @LastEditTime: 2021-04-26 21:39:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++11/initializer_list.cpp
 */

#include <iostream>
#include <initializer_list>
using namespace std;
void print(std::initializer_list<int> val)
{
    for(auto x : val)
    {
        cout << x << endl;
    }
}

class test
{
public:
    test(int a,int b)
    {
        cout << "test(int,int)  a:" << a << "  b:" << b << endl;
    }
    test(initializer_list<int> init)
    {
        cout << "initializer_list... ";
        for(auto x : init)
            cout << x << ' ';
        cout << endl;
    }
};
int main()
{
    print({3,1,5,3,5,6,67,8});

    test t1(1, 2);
    test t2{1,2};
    test t3{1, 3, 5, 7};
    test t4 = {1, 2};
    return 0;
}