#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        int n = digits.size();
        set<int> res;

        for (int i = 0; i < n; ++i)
        {
            if (digits[i] == 0)
                continue;

            for (int j = 0; j < n; ++j)
            {
                if (j == i)
                    continue;

                for (int k = 0; k < n; ++k)
                {
                    if (k == j || k == i || digits[k] & 1 == 1)
                        continue;

                    int ans = digits[k] + digits[j] * 10 + digits[i] * 100;
                    res.insert(ans);
                }
            }
        }

        return {res.begin(), res.end()};
    }
};

vector<int> parseInputDigits()
{
    vector<int> digits;
    string input;

    cout << "请输入数字数组（0-9，用空格分隔，例如：2 1 3 0 2）：";
    getline(cin, input);

    istringstream iss(input);
    int digit;
    while (iss >> digit)
    {
        if (digit < 0 || digit > 9)
        {
            cout << "错误：数字必须在0-9范围内！" << endl;
            return {};
        }
        digits.push_back(digit);
    }

    if (digits.size() < 3)
    {
        cout << "错误：至少需要3个数字！" << endl;
        return {};
    }

    return digits;
}

void printResult(const vector<int> &digits, const vector<int> &result)
{
    cout << "\n测试结果：" << endl;
    cout << "输入数字: [";
    for (size_t i = 0; i < digits.size(); ++i)
    {
        if (i != 0)
            cout << ", ";
        cout << digits[i];
    }
    cout << "]" << endl;

    cout << "所有可能的三位偶数: [";
    for (size_t i = 0; i < result.size(); ++i)
    {
        if (i != 0)
            cout << ", ";
        cout << result[i];
    }
    cout << "]" << endl;

    cout << "共找到 " << result.size() << " 个符合条件的数字" << endl;
}

int main()
{
    Solution solution;

    cout << "=== 三位偶数生成器 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        vector<int> digits = parseInputDigits();
        if (digits.empty())
        {
            continue;
        }

        vector<int> result = solution.findEvenNumbers(digits);
        printResult(digits, result);

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