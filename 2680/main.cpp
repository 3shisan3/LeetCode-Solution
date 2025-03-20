#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <cmath>     // for log2

using namespace std;

class Solution
{
public:
    int getBinaryBitNum(int value)
    {
        // 题知值为正数
        if (value == 0)
            return 1;
        return (int)log2(value) + 1; // 计算以 2 为底的对数并取整+1
    }

    long long maximumOr(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), std::greater<int>()); // 从大到小排序

        int maxBitNum = getBinaryBitNum(nums.front());      // 便于理解，不然下文提高效率可改边判断方式

        int index = 1;
        if (maxBitNum > k)
        {
            // 考虑从左到右前k个有效位数相同数或结果的情况
            while (index < nums.size() &&
                   (nums[index] >> (maxBitNum - k)) == (nums[index - 1] >> (maxBitNum - k)))
            {
                index++;
            }
        }

        // 比较
        vector<long long> resVec(index, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < index; j++)
            {
                if (j == i)
                {
                    resVec[j] |= (long long)nums[i] << k;
                }
                else
                {
                    resVec[j] |= nums[i];
                }
            }
        }

        sort(resVec.begin(), resVec.end());
        return resVec.back();
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    int k, input;

    cout << "Enter numbers (enter -1 to finish input): ";
    while (cin >> input)
    {
        if (input == -1)
        {
            break;
        }
        nums.push_back(input);
    }

    cout << "Enter the value of k: ";
    cin >> k;

    long long result = solution.maximumOr(nums, k);
    cout << "The maximum OR value is: " << result << endl;

    return 0;
}

/* 
class Solution {
public:
    using ll = long long;
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> suf(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] | nums[i];
        }

        ll res = 0;
        ll pre = 0;
        for (int i = 0; i < n; i++) {
            // 核心，从左往右 取左半部分而或从右向左记录右半部分，这样res每次取舍时
            // 就会过滤掉被选中 << k 的数影响的右半部分内容，并且替换掉之前的左半部分
            // 最后合并就是原来的数
            res = max(res, pre | (1ll * nums[i] << k) | suf[i + 1]);
            pre |= nums[i];
        }
        return res;
    }
};

// 另一解 位运算单纯是利用 异或 的原理取代了上文记录右半部分的工作，同样目的是剥离出被选为 << k 的数对右半部的影响
*/