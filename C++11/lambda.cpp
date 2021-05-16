/*
 * @Author: your name
 * @Date: 2021-05-09 21:53:11
 * @LastEditTime: 2021-05-09 22:38:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++11/lambda.cpp
 */
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
    auto lam1 = []() {};    // lambda类似于一种仿函数，创建一个对象然后返回，调用时候直接使用()运算符调用。可以将lambda抽象理解为一个带有重载()的类。
    lam1();

    []() { cout << "lambda 2." << endl; }(); //{}后直接加()，在定义后马上调用
    
    auto lam3 = [] { cout << "lambda 3" << endl; }; // {}里面写函数体
    lam3();

    auto lam4 = []() -> int { return 1; };  // 返回值使用->指定
    cout << "lam4 ret:" << lam4() << endl;

    // lambda 以[]开头，[]内放外部变量，可放引用或值
    // lambda 的()内放参数，在调用lambda的时候传入参数
    // lambda 的{}内放函数体
    int id = 0;
    // mutable 关键字表示可以修改[]内传入的变量，如果不带此关键字，那么修改由[]传入的外部变量，会报错
    // 通过[]内传入lambda的变量，不会随着外部变量变化而变化，但是在lambda函数内部修改变量，是可以改变的。可以将其理解为lambda的成员变量
    auto lam5 = [id]() mutable { cout << "id:" << id << endl; id ++; };
    id = 3;
    lam5();
    lam5();
    lam5();
    cout << id << endl;

    id = 0;
    // lambda 以引用方式添加外部变量，在函数内可以直接修改其值，修改后，外部同时也会被修改
    // [=] 表示外部变量全部以值方式传入lambda
    // [&] 表示外部变量全部以引用方式传入lambda
    // 上面两个符号，也可以作用于单个变量，将不同的变量按照需要以不同方式传入lambda。符号后不加变量名时，默认表示全部变量！ 
    auto lam6 = [&id]() {
        cout << "lam6:" << id;
        id++;
    };
    lam6();
    cout << "after lam6() id:" << id << endl;

    auto cmp = [](int x, int y) {
        return x < y;
    };
    //set<int, decltype(cmp)> sCmpLambda();
    // 这个编译不通过，是因为set对象在构造函数中如果不传入比较函数的话，编译器会调用模板第二参数的默认构造
    // 而lambda不支持默认构造，因此会报错，需要写成下面这样
    set<int, decltype(cmp)> sCmpLambda(cmp);
    vector<int> vi{3, 4, 1, 6, 9, 55, 7, 2, 100, 43, 23, 64, 62, 13, 68};
    int x = 30;
    int y = 60;
    // 删除30到60之间的数
    // remove_if会将要删除的元素移动到end迭代器之前，函数本身并不会删除元素，需要结合erase使用
    vi.erase(remove_if(vi.begin(), vi.end(),
                       [x, y](int n) {
                           return x < n && y > n;
                       }));
    for(int i : vi)
        cout << i << "  ";
    cout << endl;
    return 0;
}