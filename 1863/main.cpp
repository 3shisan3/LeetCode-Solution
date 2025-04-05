#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Solution
{
public:
    void xorSum(int startIndex, vector<int> &nums, int calNum, int val, vector<int> &xorVec)
    {
        if (startIndex + calNum > nums.size())
        {
            return;
        }

        if (calNum == 0)
        {
            xorVec.push_back(val);
            return;
        }

        for (int i = startIndex; i < nums.size(); ++i)
        {
            int temp = val ^ nums[i];
            xorSum(i + 1, nums, calNum - 1, temp, xorVec);
        }
    }

    int subsetXORSum(vector<int> &nums)
    {
        vector<int> xorVec;

        for (int calNum = 1; calNum <= nums.size(); calNum++)
        {
            xorSum(0, nums, calNum, 0, xorVec);
        }

        int res = 0;
        for (const auto &val : xorVec)
        {
            res += val;
        }

        return res;
    }
};

/* 求异或应该有数学规律，后续研究 */

vector<int> parseInput(const string &input)
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

    cout << "请输入整数数组（格式如[1,3]）：" << endl;
    getline(cin, input);

    vector<int> nums = parseInput(input);
    if (nums.empty())
    {
        return 1;
    }

    int result = solution.subsetXORSum(nums);
    cout << "所有子集异或和的总和为: " << result << endl;

    return 0;
}