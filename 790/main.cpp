#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/* 
动态规划
dp[i][0]表示到长度i为止,上一轮恰好补齐的情况有多少种方法
dp[i][1]表示到长度i为止,最后一块缺了右下角一个位置有多少种方法
dp[i][2]表示到长度i为止,最后一块缺了右上角一个位置有多少种方法
dp[i][3]表示到长度i为止,最后一块恰好补齐的情况有多少种方法
*/

using namespace std;

const long long mod = 1e9 + 7;

class Solution
{
public:
    int numTilings(int n)
    {
        if (n == 0)
            return 0;
        vector<vector<long long>> dp(n + 1, vector<long long>(4));
        dp[0][3] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = dp[i - 1][3];
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        return dp[n][3];
    }
};

int getInputN()
{
    int n;
    string input;

    while (true)
    {
        cout << "请输入棋盘长度n（1 ≤ n ≤ 1000）：";
        getline(cin, input);
        istringstream iss(input);
        if (iss >> n && n >= 1 && n <= 1000)
        {
            return n;
        }
        cout << "输入无效，请输入1到1000之间的整数！" << endl;
    }
}

void printTestResult(int n, int result)
{
    cout << "\n测试结果：" << endl;
    cout << "棋盘长度: " << n << endl;
    cout << "不同的铺砖方式数量: " << result << endl;
}

int main()
{
    Solution solution;

    cout << "=== 棋盘铺砖方式计算 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        int n = getInputN();
        int result = solution.numTilings(n);
        printTestResult(n, result);

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