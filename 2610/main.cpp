#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> res;

        map<int, int> num_times_map;
        int maxHangNum = 1;
        for (int key : nums)
        {
            int val = 1;
            if (num_times_map.count(key) > 0)
            {
                val = num_times_map[key];
                num_times_map[key] = ++val;
                maxHangNum = maxHangNum > val ? maxHangNum : val;
            }
            else
            {
                num_times_map[key] = val;
            }
        }

        res.resize(maxHangNum);

        for (auto pair : num_times_map)
        {
            int hang = 0;
            while (hang < pair.second)
            {
                res[hang++].push_back(pair.first);
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    int input;

    cout << "Enter numbers (enter -1 to finish input): ";
    while (cin >> input)
    {
        if (input == -1)
        {
            break;
        }
        nums.push_back(input);
    }

    vector<vector<int>> result = solution.findMatrix(nums);

    cout << "The resulting matrix is:" << endl;
    for (const auto &row : result)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}


/* 此解答方便理解，其中第二次遍历map的操作可以合并到第一次遍历数组中
   （通过没遍历到一个数，查询当前在map中的value，直接存入到对应行）
   提高代码运行效率
*/