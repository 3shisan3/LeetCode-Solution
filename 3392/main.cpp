#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i + 2 < nums.size(); ++i)
        {
            if ((nums[i + 2] + nums[i]) * 2 == nums[i + 1])
            {
                res++;
            }
        }
        return res;
    }
};

vector<int> parseInputArray()
{
    vector<int> nums;
    string input;

    cout << "请输入整数数组（至少3个元素，空格分隔，例如：1 2 3 4 5）：";
    getline(cin, input);

    istringstream iss(input);
    int num;
    while (iss >> num)
    {
        nums.push_back(num);
    }

    return nums;
}

void printTestResult(const vector<int> &nums, int result)
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

    cout << "满足条件的子数组数量: " << result << endl;
}

int main()
{
    Solution solution;

    cout << "=== 特殊子数组统计测试 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        vector<int> nums = parseInputArray();

        if (nums.size() < 3)
        {
            cout << "数组长度不足3个元素，请重新输入！" << endl;
            continue;
        }

        int result = solution.countSubarrays(nums);
        printTestResult(nums, result);

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