#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        long long res = 0;
        map<int, int> note; // key : nums[i] value : times

        // 获得满足k情况时左右下标
        int leftIndex = 0, rightIndex = -1;
        int curK = 0;
        for (; leftIndex < nums.size(); ++leftIndex)
        {
            while (curK < k && rightIndex + 1 < nums.size())
            {
                ++rightIndex;
                curK += note[nums[rightIndex]];
                ++note[nums[rightIndex]];
            }
            if (curK >= k)
            {
                res += nums.size() - rightIndex;
            }

            --note[nums[leftIndex]];
            curK -= note[nums[leftIndex]];
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
    int k;

    cout << "请输入数组（格式如[1,1,1,1,1]）: ";
    getline(cin, input);

    cout << "请输入k的值: ";
    cin >> k;

    vector<int> nums = parseArray(input);
    if (nums.empty())
    {
        return 1;
    }

    long long result = solution.countGood(nums, k);
    cout << "满足条件的子数组数量为: " << result << endl;


    return 0;
}