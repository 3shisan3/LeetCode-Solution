#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());

        int endIndex = tmp.size() - 1;
        int startIndex = 0;
        // vector<int> res;    // 题目定好只有一个答案

        while (startIndex < endIndex)
        {
            endIndex = std::lower_bound(tmp.begin() + startIndex,
                                        tmp.begin() + endIndex,
                                        target - tmp[startIndex]) -
                       tmp.begin();

            if (tmp[startIndex] + tmp[endIndex] == target)
            {
                int first = std::find(nums.begin(), nums.end(), tmp[startIndex]) - nums.begin();
                int second = prev(std::find(nums.rbegin(), nums.rend(), tmp[endIndex]).base()) - nums.begin();
                return {first, second};
            }
            
            startIndex++;
        }

        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    string input;

    // 输入数组
    cout << "请输入整数数组（用空格分隔，例如：2 7 11 15）:" << endl;
    getline(cin, input);
    istringstream iss(input);
    int num;
    while (iss >> num)
    {
        nums.push_back(num);
    }

    // 输入目标值
    int target;
    cout << "请输入目标值（例如：9）:" << endl;
    cin >> target;

    // 保留原始数组副本用于对比
    vector<int> original_nums = nums;

    // 执行算法
    vector<int> res = sol.twoSum(nums, target);

    // 输出结果
    cout << "\n--- 结果报告 ---" << endl;

    if (!res.empty())
    {
        cout << "找到下标: [" << res[0] << ", " << res[1] << "]" << endl;
        cout << "对应值: " << nums[res[0]] << " + " << nums[res[1]] << " = " << nums[res[0]] + nums[res[1]] << endl;
    }
    else
    {
        cout << "\n未找到有效解" << endl;
    }

    return 0;
}