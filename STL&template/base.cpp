/*
 * @Description: ***
 * @Author: Lilin
 * @Date: 2021-03-28 08:50:20
 * @LastEditTime: 2021-03-28 09:07:56
 */

/*
    STL六大部件：container（容器）、allocator（分配器）、iterator（迭代器）、algorithm（算法）、function（仿函数）、adapter（适配器）
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int ia[6] = {27, 210, 12, 47, 109, 83};
    vector<int, allocator<int> > vi(ia, ia + 6);
    //vector -> container
                //allocator -> allocator
    cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40))) << endl;
            //count_if -> algorithm
                     //begin & end -> iterator
                                           //not1 -> function adapter(negator)
                                                //bind2nd -> function adapter(binder)
                                                        //less -> function object
    return 0;
}