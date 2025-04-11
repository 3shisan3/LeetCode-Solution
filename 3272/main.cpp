#include <iostream>
#include <functional>
#include <chrono>

using namespace std;

class Solution
{
public:
    long long countGoodIntegers(int n, int k)
    {
        long long count = 0;
        // 遍历所有n位数字
        for (long long num = pow(10, n - 1); num < pow(10, n); ++num)
        {
            if (isGoodInteger(num, k))
            {
                ++count;
            }
        }
        return count;
    }

    bool isGoodInteger(long long num, int k)
    {
        string s = to_string(num);
        // 统计数字频率
        vector<int> freq(10, 0);
        for (char c : s)
        {
            freq[c - '0']++;
        }
        // 检查是否可以组成回文
        int odd = 0;
        for (int f : freq)
        {
            if (f % 2 != 0)
            {
                odd++;
            }
        }
        if (odd > 1)
        {
            return false;
        }
        // 检查是否存在排列是回文且能被k整除
        // 这里需要生成所有排列并检查，但实际中需要优化
        // 可以使用回溯生成排列
        return canFormKPalindrome(s, k);
    }

    bool canFormKPalindrome(string s, int k)
    {
        // 回溯生成所有排列，检查是否有回文且能被k整除
        // 注意避免前导零
        sort(s.begin(), s.end());
        do
        {
            if (s[0] == '0')
                continue;
            if (isPalindrome(s) && stoll(s) % k == 0)
            {
                return true;
            }
        } while (next_permutation(s.begin(), s.end()));
        return false;
    }

    bool isPalindrome(const string &s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
/* 超时，其他解（核心先生成所有可得回文串，再数学获得可用的其他组合

vector<long> pal[10];
auto init = []
{
    // 严格按顺序从小到大生成所有回文数（不用字符串转换）
    for (int j = 0; j <= 4; j++)
    {
        int base = pow(10, j);

        // 生成奇数长度回文数
        for (int i = base; i < base * 10; i++)
        {
            long x = i;
            for (int t = i / 10; t; t /= 10)
            {
                x = x * 10 + t % 10;
            }
            pal[2 * j].push_back(x);
        }
        // 生成偶数长度回文数
        if (base <= 10000)
        {
            for (int i = base; i < base * 10; i++)
            {
                long x = i;
                for (int t = i; t; t /= 10)
                {
                    x = x * 10 + t % 10;
                }
                pal[2 * j + 1].push_back(x);
            }
        }
    }
    // pal.push_back(1'000'000'001); // 哨兵，防止下面代码中的 i 下标越界
    return 0;
}();
class Solution
{
public:
    long long countGoodIntegers(int n, int k)
    {
        long fac[11];
        fac[0] = 1;
        for (int i = 1; i <= 10; i++)
        {
            fac[i] = fac[i - 1] * i;
        }

        long long ans = 0;
        unordered_set<string> us;

        for (long long t : pal[n - 1])
        {
            if (t % k == 0)
            {
                string s = to_string(t);
                sort(s.begin(), s.end());
                us.insert(s);
            }
        }
        for (string s : us)
        {
            int cnt[10] = {0};
            for (char c : s)
            {
                cnt[c - '0']++;
            }
            long cur = fac[n - 1] * (n - cnt[0]);
            for (int i = 0; i < 10; i++)
            {
                cur /= fac[cnt[i]];
            }
            ans += cur;
        }

        return ans;
    }
};

*/

int main()
{
    Solution solution;
    int n, k;

    cout << "请输入整数位数 n: ";
    cin >> n;

    cout << "请输入模数 k: ";
    cin >> k;

    if (n <= 0 || k <= 0)
    {
        cout << "错误：n 和 k 必须为正整数" << endl;
        return 1;
    }

    auto start = chrono::high_resolution_clock::now();
    long long result = solution.countGoodIntegers(n, k);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "位数为 " << n << " 且满足条件的好整数数量为: " << result << endl;
    cout << "计算耗时: " << duration.count() << " 毫秒" << endl;

    return 0;
}