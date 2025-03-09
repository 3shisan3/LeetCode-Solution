#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution
{
public:
    void addStr(vector<string> &ans, string &curStr, int leftNum, int rightNum, int strSize)
    {
        if (curStr.size() == strSize)
        {
            ans.emplace_back(curStr);
            return;
        }

        if (leftNum < strSize / 2)
        {
            curStr.push_back('(');
            addStr(ans, curStr, leftNum + 1, rightNum, strSize);
            curStr.pop_back();
        }

        if (leftNum > rightNum)
        {
            curStr.push_back(')');
            addStr(ans, curStr, leftNum, rightNum + 1, strSize);
            curStr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        int size = n * 2;

        string curStr;
        vector<string> res;
        addStr(res, curStr, 0, 0, size);

        return res;
    }
};

int main()
{
    int n;
    cout << "输入n的值（输入负数退出）: ";

    while (cin >> n)
    {
        if (n < 0)
        {
            cout << "程序已退出。" << endl;
            break;
        }

        Solution solution;
        vector<string> result = solution.generateParenthesis(n);

        cout << "n = " << n << " 的有效括号组合共 " << result.size() << " 个：" << endl;
        for (const string &s : result)
        {
            cout << s << endl;
        }
        cout << "\n输入下一个n的值（负数退出）: ";
    }

    return 0;
}