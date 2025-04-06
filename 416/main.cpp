#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stack>
#include <sstream>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        auto [sumVal, maxVal] = std::accumulate(
            nums.begin(), nums.end(),
            std::make_pair(0, 0), // 初始值: (sum, max)
            [](auto acc, int x)
            {
                return std::make_pair(acc.first + x, std::max(acc.second, x));
            });

        if (sumVal % 2 != 0)
        {
            return false;
        }

        int costVal = sumVal / 2;
        if (maxVal > costVal)
        {
            return false;
        }
        
        /* 动态规划，构建二维数组，做状态转移，画图即可理解。 */
        vector<int> dp(costVal + 1, 0);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            for (int j = costVal; j >= num; --j)
            {
                dp[j] |= dp[j - num];
            }
        }
        return dp[costVal];
    }
};

vector<int> parseInput(const string &input)
{
    vector<int> nums;
    stringstream ss(input);
    char ch;
    int num;

    // 跳过开头的'['
    ss >> ch;
    if (ch != '[')
    {
        cerr << "错误：输入应以'['开头" << endl;
        return nums;
    }

    // 读取数字直到遇到']'
    while (ss >> num)
    {
        nums.push_back(num);
        ss >> ch;
        if (ch == ']')
            break;
        if (ch != ',')
        {
            cerr << "错误：数字之间应以逗号分隔" << endl;
            return vector<int>();
        }
    }

    if (ch != ']')
    {
        cerr << "错误：输入应以']'结尾" << endl;
        return vector<int>();
    }

    return nums;
}

int main()
{
    Solution solution;
    string input;

    cout << "请输入整数数组（格式如[1,5,11,5]）：";
    getline(cin, input);

    vector<int> nums = parseInput(input);
    if (nums.empty())
    {
        return 1;
    }

    bool result = solution.canPartition(nums);
    cout << "数组" << input << (result ? "可以" : "不能") << "分割成两个和相等的子集" << endl;

    return 0;
}