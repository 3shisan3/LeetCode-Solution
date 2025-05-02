#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int dealFunc(vector<int> &tops, vector<int> &bottoms, int target)
    {
        int n = tops.size();
        int times_top = 0;
        int times_bottom = 0;
        for (int i = 0; i < n; ++i)
        {
            if (bottoms[i] != target && tops[i] != target)
            {
                return -1;
            }

            if (tops[i] == target && bottoms[i] != target)
            {
                times_bottom++;
            }
            else if (tops[i] != target && bottoms[i] == target)
            {
                times_top++;
            }
        }

        return times_bottom > times_top ? times_top : times_bottom;
    }

    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        map<int, int> val_nums_tops;
        map<int, int> val_nums_bottoms;

        int n = tops.size();
        for (int i = 0; i < n; ++i)
        {
            val_nums_tops[tops[i]]++;
            val_nums_bottoms[bottoms[i]]++;
        }

        int result = -1;
        for (const auto &val : val_nums_tops)
        {
            if (val_nums_bottoms.find(val.first) != val_nums_bottoms.end() &&
                val_nums_bottoms[val.first] + val.second >= n)
            {
                int temp = dealFunc(tops, bottoms, val.first);
                if (result == -1)
                {
                    result = temp;
                }
                else
                {
                    result = temp != -1 && temp < result ? temp : result;
                }
            }
        }

        return result;
    }
};

/* 简化版
int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    int temp1 = dealFunc(tops, bottoms, tops[0]);
    int temp2 = dealFunc(tops, bottoms, bottoms[0]);

    if (temp1 == -1)
        return temp2;
    if (temp2 == -1)
        return temp1;
    return min(temp1, temp2);
}
*/

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

void printTestResult(int result)
{
    cout << "\n测试结果：" << endl;
    if (result == -1)
    {
        cout << "无法使所有行显示相同数字" << endl;
    }
    else
    {
        cout << "最少需要交换次数: " << result << endl;
    }
}

int main()
{
    Solution solution;

    cout << "=== 多米诺骨牌最小交换次数计算 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        vector<int> tops = parseInputArray("请输入顶部数字数组（用空格分隔）：");
        vector<int> bottoms = parseInputArray("请输入底部数字数组（用空格分隔）：");

        if (tops.size() != bottoms.size())
        {
            cout << "两个数组长度必须相同，请重新输入！" << endl;
            continue;
        }

        if (tops.empty())
        {
            cout << "数组不能为空，请重新输入！" << endl;
            continue;
        }

        int result = solution.minDominoRotations(tops, bottoms);
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