#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long sum1 = 0, sum2 = 0;
        int zeroNum1 = 0, zeroNum2 = 0;

        for (const int val : nums1)
        {
            sum1 += val;
            if (val == 0)
            {
                zeroNum1++;
            }
        }
        for (const int val : nums2)
        {
            sum2 += val;
            if (val == 0)
            {
                zeroNum2++;
            }
        }

        if ((zeroNum1 == 0 && zeroNum2 == 0 && sum1 != sum2) ||
            (zeroNum1 == 0 && sum1 < sum2 + zeroNum2) ||
            (zeroNum2 == 0 && sum2 < sum1 + zeroNum1))
        {
            return -1;
        }

        return max(sum1 + zeroNum1, sum2 + zeroNum2);
    }
};

vector<int> parseInputArray(const string &prompt)
{
    vector<int> nums;
    string input;

    cout << prompt;
    getline(cin, input);

    istringstream iss(input);
    int num;
    while (iss >> num)
    {
        nums.push_back(num);
    }

    return nums;
}

void printResult(long long result)
{
    cout << "\n测试结果: ";
    if (result == -1)
    {
        cout << "无法使两个数组和相等" << endl;
    }
    else
    {
        cout << "最小可能和为: " << result << endl;
    }
}

int main()
{
    Solution solution;

    cout << "=== 数组最小和计算 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        vector<int> nums1 = parseInputArray("请输入第一个数组（空格分隔，例如：1 0 2 4）：");
        vector<int> nums2 = parseInputArray("请输入第二个数组（空格分隔，例如：1 3 0 4）：");

        long long result = solution.minSum(nums1, nums2);
        printResult(result);

        cout << "\n是否继续测试？(y/n): ";
        string choice;
        getline(cin, choice);

        if (choice == "n" || choice == "N" || choice == "q")
        {
            break;
        }
    }

    return 0;
}