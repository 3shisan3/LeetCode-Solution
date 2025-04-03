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
        int num = nums.size();

        vector<int> left(num), right(num);
        left[0] = nums.front();
        right[num - 1] = nums.back();
        for (int j = 1; j < num - 1; j++)
        {
            left[j] = max(left[j - 1], nums[j - 1]);
            right[num - j - 1] = max(right[num - j], nums[num - j]);
        }

        long long res = 0;
        for (int j = 1; j < num - 1; j++)
        {
            res = max(res, (long long)(left[j] - nums[j]) * right[j]);
        }

        return res;
    }
};

vector<int> parseArrayInput(const string &input)
{
    vector<int> nums;
    stringstream ss(input);
    char ch;
    int num;

    // 验证并跳过开头的'['
    ss >> ch;
    if (ch != '[')
    {
        cerr << "错误：输入格式不正确，应以'['开头" << endl;
        return nums;
    }

    // 读取数字直到遇到']'
    while (ss >> num)
    {
        nums.push_back(num);
        // 读取下一个字符（可能是逗号或']'）
        ss >> ch;
        if (ch == ']')
            break;
        if (ch != ',')
        {
            cerr << "错误：数字之间应以逗号分隔" << endl;
            return vector<int>();
        }
    }

    // 检查是否正常结束
    if (ch != ']')
    {
        cerr << "错误：输入格式不正确，应以']'结尾" << endl;
        return vector<int>();
    }

    return nums;
}

int main()
{
    Solution solution;
    string input;

    cout << "请输入整数数组（格式如[12,6,1,2,7]）：" << endl;
    getline(cin, input);

    vector<int> nums = parseArrayInput(input);
    if (nums.empty())
    {
        return 1;
    }

    if (nums.size() < 3)
    {
        cerr << "错误：数组长度必须至少为3" << endl;
        return 1;
    }

    long long result = solution.maximumTripletValue(nums);
    cout << "最大三元组值为: " << result << endl;

    return 0;
}