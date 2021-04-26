/*
 * @Author: your name
 * @Date: 2021-04-22 21:51:17
 * @LastEditTime: 2021-04-26 21:27:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++11/Variadic_Templates.cpp
 */

#include <iostream>
#include <functional>
using namespace std;
struct xxx
{
    int ak;
    int b;
};
namespace std
{
    template <>
    class hash<xxx>
    {
    public:
        size_t operator()(const xxx &t)
        {
            return t.ak + t.b;
        }
    };
}
void print()
{}
template <typename T,typename... Types>
void print(const T& firstArg,const Types&... args)
{
    cout << firstArg << endl;
    print(args...);
}

template<typename T>
void hash_combine(size_t &seed,const T &val)
{
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template<typename T>
void hash_val(size_t &seed, const T &val)
{
    hash_combine(seed, val);
}

template<typename T, typename... Types>
void hash_val(size_t &seed,const T& val,const Types&... args)
{
    hash_combine(seed, val);
    hash_val(seed, args...);
}
template<typename... Types>
size_t hash_val(const Types&... args)
{
    size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

int main()
{
    print(1, 2, 3, "xxx", bitset<16>(377), 99);
    cout << "c++" << __cplusplus << endl;
    cout << hash_val(1, 3, 3.3,string("aaa"),'x',xxx()) << endl;
    return 0;
}