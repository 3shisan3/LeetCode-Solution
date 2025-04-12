#include <iostream>
#include <functional>

using namespace std;

class Solution
{
public:
    static constexpr int MOD = 1e9 + 7;

    int countGoodNumbers(long long n)
    {
        auto quickmul = [](int x, long long y) -> int
        {
            int ret = 1, mul = x;
            while (y > 0)
            {
                if (y % 2 == 1)
                {
                    ret = (long long)ret * mul % MOD;
                }
                mul = (long long)mul * mul % MOD;
                y /= 2;
            }
            return ret;
        };

        return (long long)quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % MOD;
    }
};

/* 大规模幂计算，快速幂秒了 */

int main()
{
    Solution solution;
    long long n;

    cout << "请输入数字长度 n: ";
    cin >> n;

    if (n < 0)
    {
        cout << "错误：n 不能为负数" << endl;
        return 1;
    }

    int result = solution.countGoodNumbers(n);
    cout << "长度为 " << n << " 的好数字数量为: " << result << endl;
    cout << "结果模 " << Solution::MOD << " 的值为: " << result << endl;

    return 0;
}