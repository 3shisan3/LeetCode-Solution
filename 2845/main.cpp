#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
// 前缀和写法
class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        long long res = 0;
        vector<int> cnt(min(modulo, (int)nums.size() + 1));
        cnt[0] = 1;
        long long s = 0;
        for (const auto &n : nums)
        {
            s += n % modulo == k;
            if (s >= k)
            {
                res += cnt[(s - k) % modulo];
            }
            ++cnt[s % modulo];
        }
        return res;
    }
};

// 暴力思路
class Solution2
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        vector<int> sucIndex;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] % modulo == k)
            {
                sucIndex.emplace_back(i);
            }
        }

        long long res = 0;
        int n = sucIndex.size();
        // 子数组需包含sucIndex数量
        int cnt = k; // 0 * modulo + k
        if (cnt == 0)
        {
            int lastIndex = -1;
            for (int i = 0; i < n; ++i)
            {
                int num = sucIndex[i] - lastIndex - 1;

                res += (num + 1) * num / 2;
                lastIndex = sucIndex[i];
            }
            {
                int num = nums.size() - lastIndex - 1;
                res += (num + 1) * num / 2;
            }

            cnt += modulo;
        }
        while (cnt <= n)
        {
            int leftIndex = -1;
            int rightIndex = sucIndex[cnt - 1];
            // 滑动窗口
            for (int i = 0; i + cnt < n; ++i)
            {
                int left = sucIndex[i] - leftIndex;         // 左边范围数量
                int right = sucIndex[i + cnt] - rightIndex; // 右边范围
                res += left * right;

                leftIndex = sucIndex[i];
                rightIndex = sucIndex[i + cnt];
            }
            {
                int left = sucIndex[n - cnt] - leftIndex; // 左边范围数量
                int right = nums.size() - rightIndex;     // 右边范围
                res += left * right;
            }

            cnt += modulo;
        }

        return res;
    }
};

vector<int> parseInputArray()
{
    vector<int> nums;
    string input;

    cout << "请输入整数数组（用空格分隔，例如：1 2 3 4 5）: ";
    getline(cin, input);

    istringstream iss(input);
    int num;
    while (iss >> num)
    {
        nums.push_back(num);
    }

    return nums;
}

int parseInputInt(const string &prompt)
{
    int value;
    string input;

    cout << prompt;
    getline(cin, input);
    istringstream iss(input);
    iss >> value;

    return value;
}

int main()
{
    Solution solution;

    while (true)
    {
        cout << "\n=== 测试 countInterestingSubarrays ===" << endl;

        vector<int> nums = parseInputArray();
        if (nums.empty())
        {
            cout << "输入为空，请重新输入！" << endl;
            continue;
        }

        int modulo = parseInputInt("请输入模数 (modulo): ");
        int k = parseInputInt("请输入 k 值: ");

        long long result = solution.countInterestingSubarrays(nums, modulo, k);
        cout << "满足条件的子数组数量: " << result << endl;

        cout << "\n是否继续测试？(y/n): ";
        char choice;
        cin >> choice;
        cin.ignore(); // 清除输入缓冲区

        if (tolower(choice) != 'y')
        {
            break;
        }
    }

    return 0;
}