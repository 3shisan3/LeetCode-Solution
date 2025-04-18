#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        long long res = (long long)n * (n - 1) / 2;
        // 记录 下标上值 - 下标
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i)
        {
            res -= mp[nums[i] - i];
            mp[nums[i] - i]++;
        }

        return res;
    }
};

vector<int> parseArray(const string &input)
{
    vector<int> arr;
    stringstream ss(input);
    char ch;
    int num;

    // 跳过开头的'['
    ss >> ch;
    if (ch != '[')
    {
        cerr << "Error: Input should start with '['" << endl;
        return arr;
    }

    // 读取数字直到遇到']'
    while (ss >> num)
    {
        arr.push_back(num);
        ss >> ch;
        if (ch == ']')
            break;
        if (ch != ',')
        {
            cerr << "Error: Numbers should be comma-separated" << endl;
            return vector<int>();
        }
    }

    if (ch != ']')
    {
        cerr << "Error: Input should end with ']'" << endl;
        return vector<int>();
    }

    return arr;
}

int main()
{
    Solution solution;
    string input;

    cout << "请输入数组（格式如[4,1,3,3]）: ";
    getline(cin, input);

    vector<int> nums = parseArray(input);
    if (nums.empty())
    {
        return 1;
    }

    long long result = solution.countBadPairs(nums);
    cout << "坏数对的数量为: " << result << endl;

    return 0;
}