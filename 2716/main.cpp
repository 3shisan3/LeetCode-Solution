#include <iostream>
#include <string>
#include <cctype> // 用于 islower()

using namespace std;

class Solution
{
public:
    int popcount_divide(unsigned int x)
    {
        x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
        return (x * 0x01010101) >> 24;
    }

    int minimizedStringLength(string s)
    {
        int set_bit = 0;                    // 等同于set

        for (const auto c : s)
        {
            set_bit |= 1 << (c - 'a');
        }

        return popcount_divide(set_bit);
    }
};

int main()
{
    string s;
    cout << "请输入字符串（仅包含小写字母）: ";
    getline(cin, s); // 读取整行输入

    // 验证输入合法性
    for (char c : s)
    {
        if (!islower(c))
        {
            cerr << "错误：输入必须为小写字母！" << endl;
            return 1;
        }
    }

    Solution sol;
    int result = sol.minimizedStringLength(s);

    cout << "最小可能长度为: " << result << endl;

    return 0;
}