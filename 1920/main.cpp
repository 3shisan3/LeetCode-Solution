#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; ++i)
        {
            ans[i] = nums[nums[i]];
        }

        return ans;
    }
};

vector<int> parseInputArray()
{
    vector<int> nums;
    string input;

    cout << "请输入数组元素（用空格分隔，例如：0 2 1 5 3 4）：";
    getline(cin, input);

    istringstream iss(input);
    int num;
    while (iss >> num)
    {
        nums.push_back(num);
    }

    return nums;
}

void printResult(const vector<int> &nums, const vector<int> &result)
{
    cout << "\n测试结果：" << endl;
    cout << "输入数组: [";
    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (i != 0)
            cout << ", ";
        cout << nums[i];
    }
    cout << "]" << endl;

    cout << "构建后的数组: [";
    for (size_t i = 0; i < result.size(); ++i)
    {
        if (i != 0)
            cout << ", ";
        cout << result[i];
    }
    cout << "]" << endl;
}

int main()
{
    Solution solution;

    cout << "=== 数组构建测试 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        vector<int> nums = parseInputArray();
        if (nums.empty())
        {
            cout << "数组不能为空，请重新输入！" << endl;
            continue;
        }

        // 验证数组元素是否有效
        bool valid = true;
        for (int num : nums)
        {
            if (num < 0 || num >= static_cast<int>(nums.size()))
            {
                valid = false;
                break;
            }
        }
        if (!valid)
        {
            cout << "数组元素必须在0到n-1范围内，请重新输入！" << endl;
            continue;
        }

        vector<int> result = solution.buildArray(nums);
        printResult(nums, result);

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