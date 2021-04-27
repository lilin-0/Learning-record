/*
 * @Author: your name
 * @Date: 2021-04-27 19:32:28
 * @LastEditTime: 2021-04-27 20:16:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++11/explicit_test.cpp
 */

#include <iostream>
#include <initializer_list>
using namespace std;

struct test1
{
    //explicit
    test1(int a, int b = 0) : x(a), y(b){}
    test1 operator+(const test1 &t)
    {
        return test1(x + t.x, y + t.y);
    }

    int x, y;
};

struct test2
{
    test2(int a, int b) { cout << "test2(int a,int b)..." << endl; }
    explicit test2(int a, int b, int c) { cout << "explicit 3 args version" << endl; }
};
void test2_fun(const test2 &x)
{
    cout << "test2_fun()" << endl;
}
int main()
{
    test1 x(5, 6);
    test1 x1 = x + 1;
    cout << x1.x << ' ' << x1.y << endl;
    
    test2 t2_1(1, 1);
    test2 t2_2{1, 2};
    test2 t2_3{3, 3, 3};
    test2 t2_4 = {4, 4};
    //test2 t2_5 = {5, 5, 5};       // 报错，编译器不允许隐式调用构造
    test2_fun(t2_3);
    test2_fun({1, 2});
    //test2_fun({1,2,3});           // 报错，编译器不允许隐式调用构造
    return 0;
}