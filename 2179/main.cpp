#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> p(n);

        for (int i = 0; i < n; ++i)
            p[nums1[i]] = i;

        long long res = 0;
        vector<int> tree(n + 1);

        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = p[nums2[i - 1]] + 1; j <= n; j += j & -j)
                ++tree[j];

            int y = p[nums2[i]], less = 0;
            for (int j = y; j; j &= j - 1)
                less += tree[j];

            res += (long long)less * (n - 1 - y - (i - less));
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
    string input1, input2;

    cout << "请输入nums1数组（格式如[4,0,1,3,2]）: ";
    getline(cin, input1);

    cout << "请输入nums2数组（格式如[4,1,0,2,3]）: ";
    getline(cin, input2);

    vector<int> nums1 = parseArray(input1);
    vector<int> nums2 = parseArray(input2);

    if (nums1.empty() || nums2.empty())
    {
        return 1;
    }

    if (nums1.size() != nums2.size())
    {
        cerr << "Error: Two arrays must have the same length" << endl;
        return 1;
    }

    long long result = solution.goodTriplets(nums1, nums2);
    cout << "好三元组的数量为: " << result << endl;

    // 测试您提供的用例
    vector<int> testNums1 = {4, 0, 1, 3, 2};
    vector<int> testNums2 = {4, 1, 0, 2, 3};
    long long testResult = solution.goodTriplets(testNums1, testNums2);
    cout << "\n测试用例结果 (nums1=[4,0,1,3,2], nums2=[4,1,0,2,3]): " << testResult << endl;

    return 0;
}