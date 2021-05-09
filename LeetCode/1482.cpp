/*
 * @Author: your name
 * @Date: 2021-05-09 16:13:44
 * @LastEditTime: 2021-05-09 21:50:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /LeetCode/1482.cpp
 */
#include <default_header.h>

class Solution
{
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int len = bloomDay.size();
        int minDay = *min_element(bloomDay.begin(), bloomDay.end());    // 开得最快的一朵花需要的时间
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());    // 开得最慢的一朵花需要的时间
        // 花不够。总数都不够，怎么凑都不行，直接 -1
        if (len < m * k)
        {
            return -1;
        }
        // 数量刚刚好，那直接用开得最慢的那一朵花需要的时间，因为要全部都开，才可以凑够要求
        else if(len == m * k)
        {
            return maxDay;
        }
        // 其他情况：只要花的数量达标，那么，就算花开得再晚，一定会满足定条件的。
        // 所以接下来就是一个时间长短的问题。
        // 要求时间尽可能短的满足条件。最短时间是多少？想象一种极端情况，开了一朵花，就满足条件。那这个时间是多少？
        // 最短时间一定是开得最快的那一朵花需要的时间！！！会不会开0朵就满足了呢？查看题目输入要求，都是大于0的，所以不会。
        // 哪最长时间要多少？假设现在需要所有花都开完才能满足。。。（这个就是上面的else if分支）最长时间一定是开得最慢的那一朵花需要的时间。
        // 因为等最慢的花开了，所有花都开完了，时间再继续走下去，也没有新的花要开。。。岂不是浪费时间？？？
        // 综上所述，得出一个结论：题目的答案一定在minDay和maxDay这两个数之间！
        // 既然都能确定时间范围了，这就好办了，最简单暴力的方式：我把这两个日期中间所有时间遍历一下，一定能得出结果。但速度不行，更好的办法就是把日期二分查找。
        // 下面开始操作起来
        
        // 用于检查是否满足条件，lambda
        auto isOK = [&](int nowDay) -> bool {
            int cnt = 0;
            int total = 0;
            for (int &x : bloomDay)
            {
                if(x > nowDay)
                {
                    cnt = 0;
                }
                else
                {
                    cnt++;
                }
                if(cnt == k)
                {
                    total++;
                    cnt = 0;
                }
            }
            return total >= m;
        };

        // 这里开始二分
        int left = minDay;
        int right = maxDay;
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (isOK(mid))
            {
                //满足条件了，还不能返回，因为不一定是最短时间的，这里修改右侧边界，继续找
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return right + 1;   // right里面总是记录着最后一次满足条件的位置，因为上面减了1，所以这里加回来
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> bloomDay = stringToIntegerVector(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().minDays(bloomDay, m, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}