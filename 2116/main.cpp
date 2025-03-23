#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        if (s.size() % 2)
        {
            return false;
        }
        int mn = 0, mx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (locked[i] == '1')
            { // 不能改
                int d = s[i] == '(' ? 1 : -1;
                mx += d;
                if (mx < 0)
                { // c 不能为负
                    return false;
                }
                mn += d;
            }
            else
            {         // 可以改
                mx++; // 改成左括号，c 加一
                mn--; // 改成右括号，c 减一
            }
            if (mn < 0)
            {           // c 不能为负
                mn = 0; // 重置为 0
            }
        }
        return mn == 0; // 说明最终 c 能是 0
    }
};

int main()
{
    Solution solution;
    string s, locked;

    cout << "Enter the string s: ";
    cin >> s;

    cout << "Enter the locked string: ";
    cin >> locked;

    bool result = solution.canBeValid(s, locked);

    cout << "The string \"" << s << "\" "
         << (result ? "can" : "cannot")
         << " be made valid with the given locked constraints." << endl;

    return 0;
}