#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int res = 0;
        for (int val : nums)
        {
            if (to_string(val).size() % 2 == 0)
            {
                res++;
            }
        }
        return res;
    }
};

vector<int> getInputNumbers()
{
    vector<int> nums;
    string input;

    cout << "请输入整数数组（用空格分隔，例如：12 345 2 6 7896）：";
    getline(cin, input);

    istringstream iss(input);
    int num;
    while (iss >> num)
    {
        nums.push_back(num);
    }

    return nums;
}

void printResult(const vector<int> &nums, int result)
{
    cout << "\n测试结果：" << endl;
    cout << "输入数组：[";
    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (i != 0)
            cout << ", ";
        cout << nums[i];
    }
    cout << "]" << endl;

    cout << "包含偶数位数的数字数量: " << result << endl;
}

int main()
{
    Solution solution;

    cout << "=== 偶数位数数字统计 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        vector<int> nums = getInputNumbers();
        if (nums.empty())
        {
            cout << "数组不能为空，请重新输入！" << endl;
            continue;
        }

        int result = solution.findNumbers(nums);
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