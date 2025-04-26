#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long res = 0;

        int minIndex = -1, maxIndex = -1, startIndex = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            int val = nums[i];
            if (val == minK)
            {
                minIndex = i;
            }
            if (val == maxK)
            {
                maxIndex = i;
            }
            if (val < minK || val > maxK)
            {
                startIndex = i;
            }

            res += max(min(minIndex, maxIndex) - startIndex, 0);
        }

        return res;
    }
};

vector<int> parseInputArray()
{
    vector<int> nums;
    string input;

    cout << "请输入整数数组（用空格分隔，例如：1 3 5 2 7 5）：";
    getline(cin, input);

    istringstream iss(input);
    int num;
    while (iss >> num)
    {
        nums.push_back(num);
    }

    return nums;
}

int parseBound(const string &prompt)
{
    int value;
    string input;

    while (true)
    {
        cout << prompt;
        getline(cin, input);
        istringstream iss(input);
        if (iss >> value)
        {
            return value;
        }
        cout << "输入无效，请重新输入！" << endl;
    }
}

void printTestResult(const vector<int> &nums, int minK, int maxK, long long result)
{
    cout << "\n测试结果：" << endl;
    cout << "数组: [";
    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (i != 0)
            cout << ", ";
        cout << nums[i];
    }
    cout << "]" << endl;

    cout << "范围: [" << minK << ", " << maxK << "]" << endl;
    cout << "满足条件的子数组数量: " << result << endl;
}

int main()
{
    Solution solution;

    cout << "=== 子数组范围统计测试 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        vector<int> nums = parseInputArray();
        if (nums.empty())
        {
            cout << "数组不能为空，请重新输入！" << endl;
            continue;
        }

        int minK = parseBound("请输入最小值minK: ");
        int maxK = parseBound("请输入最大值maxK: ");

        if (minK > maxK)
        {
            cout << "最小值不能大于最大值，请重新输入！" << endl;
            continue;
        }

        long long result = solution.countSubarrays(nums, minK, maxK);
        printTestResult(nums, minK, maxK, result);

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