#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    int minimumSum(int n, int k)
    {
        vector<int> res;

        int val = 1; // 最小总和，成员从1开始
        while (n > 0)
        {
            if (val > k || !std::binary_search(res.begin(), res.end(), k - val))
            {
                res.emplace_back(val);
                n--;
            }
            ++val;
        }

        return std::accumulate(res.begin(), res.end(), 0);
    }
};

int main()
{
    int n, k;

    // 输入提示
    cout << "请输入 n 和 k 的值（用空格分隔，例如：5 10）: ";
    cin >> n >> k;

    // 检查输入是否合法
    if (n <= 0 || k <= 0)
    {
        cerr << "错误：n 和 k 必须为正整数！" << endl;
        return 1;
    }

    Solution sol;
    int result = sol.minimumSum(n, k);

    cout << "最小和为: " << result << endl;

    return 0;
}