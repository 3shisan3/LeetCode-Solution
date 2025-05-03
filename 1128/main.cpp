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
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        map<int, int> value_num;

        for (const auto &val : dominoes)
        {
            int cur = min((val[0] * 10 + val[1]), (val[0] + val[1] * 10));
            value_num[cur]++;
        }

        int res = 0;
        for (const auto &p : value_num)
        {
            res += p.second * (p.second - 1) / 2;
        }
        return res;
    }
};

vector<vector<int>> parseDominoes()
{
    vector<vector<int>> dominoes;
    string input;

    cout << "请输入多米诺骨牌对（格式如：1 2,3 4,5 6）：" << endl;
    cout << "（每对用空格分隔，多对用逗号分隔）" << endl;
    getline(cin, input);

    // 移除所有空格以便处理
    input.erase(remove(input.begin(), input.end(), ' '), input.end());

    istringstream iss(input);
    string pair;
    while (getline(iss, pair, ','))
    {
        if (pair.size() != 2)
        {
            cout << "输入格式错误，每对多米诺骨牌应为2个数字！" << endl;
            return {};
        }

        vector<int> domino;
        domino.push_back(pair[0] - '0');
        domino.push_back(pair[1] - '0');
        dominoes.push_back(domino);
    }

    return dominoes;
}

void printTestResult(int result)
{
    cout << "\n测试结果：" << endl;
    cout << "等价多米诺骨牌对的数量: " << result << endl;
}

int main()
{
    Solution solution;

    cout << "=== 等价多米诺骨牌对统计 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        vector<vector<int>> dominoes = parseDominoes();
        if (dominoes.empty())
        {
            cout << "输入无效，请重新输入！" << endl;
            continue;
        }

        int result = solution.numEquivDominoPairs(dominoes);
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