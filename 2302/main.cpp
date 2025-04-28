#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int left = 0, right = 0;
        int n = nums.size();

        long long res = 0;
        long long curVal = 0;
        while (right < n)
        {
            curVal += nums[right];
            while (curVal * (right - left + 1) >= k && left <= right)
            {
                curVal -= nums[left];
                left++;
            }
            right++;
            res += right - left;
        }

        return res;
    }
};

vector<int> parseInputArray()
{
    vector<int> nums;
    string input;

    cout << "请输入整数数组（用空格分隔，例如：2 1 4 3 5）：";
    getline(cin, input);

    istringstream iss(input);
    int num;
    while (iss >> num)
    {
        nums.push_back(num);
    }

    return nums;
}

long long parseThreshold()
{
    long long k;
    string input;

    while (true)
    {
        cout << "请输入阈值 k：";
        getline(cin, input);
        istringstream iss(input);
        if (iss >> k && k >= 0)
        {
            return k;
        }
        cout << "输入无效，请输入非负整数！" << endl;
    }
}

void printTestResult(const vector<int> &nums, long long k, long long result)
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

    cout << "阈值 k: " << k << endl;
    cout << "满足条件的子数组数量: " << result << endl;
}

int main()
{
    Solution solution;

    cout << "=== 子数组和与长度乘积测试 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        vector<int> nums = parseInputArray();
        if (nums.empty())
        {
            cout << "数组不能为空，请重新输入！" << endl;
            continue;
        }

        long long k = parseThreshold();
        long long result = solution.countSubarrays(nums, k);
        printTestResult(nums, k, result);

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