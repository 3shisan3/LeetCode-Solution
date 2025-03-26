#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    long long minimumCost(string s)
    {
        // 最小反转次数等于序列中「相邻字符不相同」的次数
        long long res = 0;

        int i = 0;
        for (; i < s.size() / 2; ++i)
        {
            if (s[i] != s[i + 1])
            {
                res += i + 1;
            }
        }

        for (i = s.size() - 1; i > s.size() / 2; --i)
        {
            if (s[i] != s[i - 1])
            {
                res += s.size() - i;
            }
        }

        return res;
    }
};

int main()
{
    string s;

    // 输入提示
    cout << "请输入二进制字符串 s（例如：010101）: ";
    cin >> s;

    // 检查输入是否合法（仅包含 '0' 和 '1'）
    for (char c : s)
    {
        if (c != '0' && c != '1')
        {
            cerr << "错误：输入必须为二进制字符串（仅包含 '0' 和 '1'）！" << endl;
            return 1;
        }
    }

    Solution sol;
    long long result = sol.minimumCost(s);

    cout << "最小反转成本为: " << result << endl;

    return 0;
}