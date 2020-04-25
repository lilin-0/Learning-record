/*
 * @Description: ***
 * @Author: Lilin
 * @Date: 2020-04-25 11:05:27
 * @LastEditTime: 2020-04-25 12:25:04
 */
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int arrA[100004];
int arrB[100004];
int iStep;
//void merge(vector<int> &vArr, int ibegin, int imid, int iend)
void merge(int* vArr,int ibegin, int imid, int iend)
{
    //拷贝一份
    //vector<int> vTempArr = vArr;
    for (int i = ibegin; i <= iend; i++)
        arrB[i] = arrA[i];

        int iFirst = ibegin;
    int iSecond = imid + 1;
    for (int w = ibegin; w <= iend; w++)
    {
        if (iFirst > imid)
            vArr[w] = arrB[iSecond++];
        else if (iSecond > iend)
            vArr[w] = arrB[iFirst++];
        else if (arrB[iFirst] < arrB[iSecond])
            vArr[w] = arrB[iFirst++];
        else
        {
            // 此分支存在逆序，需要计算交换次数
            vArr[w] = arrB[iSecond++];
            iStep += imid - iFirst + 1;
        }
    }
}

//void mergesort(vector<int> &vArr, int ibegin, int iend)
void mergesort(int * vArr, int ibegin, int iend)
{
    if (ibegin >= iend)
        return;
    int imid = (ibegin + iend) / 2;
    mergesort(vArr, ibegin, imid);
    mergesort(vArr, imid + 1, iend);
    merge(vArr, ibegin, imid, iend);
}

int main()
{
    int n = 0;
    //while (cin >> n)
    while(~scanf("%d", &n))
    {
        //vector<int> input;
        iStep = 0;
        for (int i = 0; i < n; i++)
        {
            int t;
            //cin >> t;
            scanf("%d", &t);
            if (i % 2 == 0) // 取奇数位置的数字
            {
                //input.emplace_back(t);
                arrA[i / 2] = t;
                if (t % 2 == 0) // 数字为偶数，需交换一次
                    iStep++;
            }
        }

        mergesort(arrA, 0, n / 2 - 1);
        //cout << iStep << endl;
        printf("%d\n", iStep);
    }

    return 0;
}