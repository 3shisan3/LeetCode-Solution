#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int flag = -1; // 有无向右推且未平衡标记
        int len = dominoes.size();

        string res = "";
        string c = "";
        for (int i = 0; i < len; ++i)
        {
            if (dominoes[i] == 'R')
            {
                c = flag == -1 ? '.' : 'R';
                while (res.size() < i)
                {
                    res += c;
                }
                res += 'R'; // 记录下当前字符
                flag = i;
            }
            else if (dominoes[i] == 'L')
            {
                if (flag == -1)
                {
                    while (res.size() < i + 1)
                    {
                        res += 'L';
                    }
                }
                else
                {
                    int right = i;
                    std::string temp = "L"; // 记录一次当前字符
                    while (right - flag > 2)
                    {
                        res += 'R';
                        temp += 'L';
                        flag++;
                        right--;
                    }

                    if (right - flag == 2)
                    {
                        res += '.';
                    }
                    res += temp;
                    flag = -1;
                }
            }
        }

        c = flag == -1 ? '.' : 'R';
        while (res.size() < len)
        {
            res += c;
        }

        return res;
    }
};

string getInputDominoes()
{
    string dominoes;
    cout << "请输入多米诺骨牌初始状态（例如：.L.R...LR..L..）：";
    getline(cin, dominoes);
    return dominoes;
}

void printResult(const string &dominoes, const string &result)
{
    cout << "\n测试结果：" << endl;
    cout << "初始状态: " << dominoes << endl;
    cout << "最终状态: " << result << endl;
}

int main()
{
    Solution solution;

    cout << "=== 多米诺骨牌推倒模拟 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        string dominoes = getInputDominoes();
        if (dominoes.empty())
        {
            cout << "输入不能为空，请重新输入！" << endl;
            continue;
        }

        string result = solution.pushDominoes(dominoes);
        printResult(dominoes, result);

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