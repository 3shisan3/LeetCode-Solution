#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution
{
public:
    const int mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int t)
    {
        long long note[26]{};
        for (const auto &c : s)
        {
            note[c - 'a']++;
        }

        long long res[26]{};
        while (t / 26)
        {
            for (int i = 0; i < 26; i++)
            {
                res[i] = (note[i] + note[(i + 25) % 26]) % mod;
            }

            res[1] += note[25];

            for (int i = 0; i < 26; i++)
            {
                note[i] = res[i];
            }
            t -= 26;
        }

        long long ans = 0;
        for (int i = 0; i < 26; ++i)
        {
            ans += i + t < 26 ? note[i] : 2 * note[i];
            ans %= mod;
        }

        return ans;
    }
};

string getValidString()
{
    string s;
    cout << "请输入小写字母字符串: ";
    getline(cin, s);

    for (char &c : s)
    {
        if (!islower(c))
        {
            cout << "错误：字符串必须全部由小写字母组成！" << endl;
            return "";
        }
    }

    return s;
}

int getValidT()
{
    int t;
    cout << "请输入变换次数 t (非负整数): ";
    while (!(cin >> t) || t < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "错误：请输入非负整数！" << endl;
        cout << "请重新输入变换次数 t: ";
    }
    cin.ignore(); // 清除输入缓冲区中的换行符
    return t;
}

void printResult(const string &s, int t, int result)
{
    cout << "\n测试结果：" << endl;
    cout << "输入字符串: \"" << s << "\"" << endl;
    cout << "变换次数: " << t << endl;
    cout << "变换后长度: " << result << " (mod " << (int)1e9 + 7 << ")" << endl;
}

int main()
{
    Solution solution;

    cout << "=== 字符串变换长度计算 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        string s = getValidString();
        if (s.empty())
            continue;

        int t = getValidT();

        int result = solution.lengthAfterTransformations(s, t);
        printResult(s, t, result);

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