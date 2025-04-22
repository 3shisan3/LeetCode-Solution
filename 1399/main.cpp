#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countLargestGroup(int n)
    {
        map<int, int> val_num;

        int cur = 1;
        while (cur <= n)
        {
            int curVal = 0;
            int temp = cur;
            while (temp % 10 != temp)
            {
                curVal += temp % 10;
                temp /= 10;
            }
            curVal += temp;

            val_num[curVal]++;

            cur++;
        }
        
        // int res = 0;
        int maxNum = 0;
        unordered_map<int, int> valueCounts;
        for (auto &pair : val_num)
        {
            maxNum = max(maxNum, pair.second);
            valueCounts[pair.second]++;
            // res = max(valueCounts[pair.second], res);
        }

        return valueCounts[maxNum];
    }
};

int main()
{
    Solution solution;

    // 用户输入测试
    int userInput;
    cout << "\n请输入一个正整数n进行测试: ";
    cin >> userInput;
    int userResult = solution.countLargestGroup(userInput);
    cout << "结果: " << userResult << endl;

    return 0;
}