#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long res = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = nums.size() - 1; k > j; k--)
                {
                    res = max(res, (long long)(nums[i] - nums[j]) * nums[k]);
                }
            }
        }

        return res;
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

    while (ss >> num)
    {
        nums.push_back(num);
        // 读取逗号或']'
        ss >> ch;
        if (ch == ']')
            break;
    }

    return nums;
}

int main()
{
    Solution solution;
    string input;

    cout << "请输入数组（格式如[12,6,1,2,7]）：" << endl;
    getline(cin, input);

    vector<int> nums = parseInput(input);

    if (nums.size() < 3)
    {
        cout << "错误：数组长度必须至少为3" << endl;
        return 1;
    }

    long long result = solution.maximumTripletValue(nums);
    cout << "最大三元组值为: " << result << endl;

    return 0;
}