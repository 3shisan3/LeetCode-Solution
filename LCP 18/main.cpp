#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int breakfastNumber(vector<int> &staple, vector<int> &drinks, int x)
    {
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        const int MOD = 1e9 + 7;

        int left = 0;
        int right = drinks.size() - 1;
        int num = staple.size();

        long long res = 0;
        while (left < num && staple[left] < x)
        {
            while (right >= 0 && drinks[right] + staple[left] > x)
            {
                right--;
            }

            if (right < 0)
            {
                break;
            }

            res += right + 1;

            left++;
        }

        return res % MOD;
    }
};

/* 另有前缀和解法 */

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

int parseX()
{
    int x;
    string input;

    while (true)
    {
        cout << "请输入预算x：";
        getline(cin, input);
        istringstream iss(input);
        if (iss >> x && x > 0)
        {
            return x;
        }
        cout << "输入无效，请输入正整数！" << endl;
    }
}

void printTestResult(int result)
{
    cout << "\n测试结果：" << endl;
    cout << "满足条件的早餐组合数量: " << result << endl;
}

int main()
{
    Solution solution;

    cout << "=== 早餐组合计算 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        vector<int> staple = parseInputArray("请输入主食价格数组（用空格分隔）：");
        vector<int> drinks = parseInputArray("请输入饮料价格数组（用空格分隔）：");
        int x = parseX();

        if (staple.empty() || drinks.empty())
        {
            cout << "输入数组不能为空，请重新输入！" << endl;
            continue;
        }

        int result = solution.breakfastNumber(staple, drinks, x);
        printTestResult(result);

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