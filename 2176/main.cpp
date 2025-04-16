#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int res = 0;

        map<int, vector<int>> val_indexs;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int val = nums[i];
            if (val_indexs.find(val) != val_indexs.end())
            {
                val_indexs[val].emplace_back(i);
            }
            else
            {
                val_indexs.insert({val, {i}});
            }
        }

        for (const auto &p : val_indexs)
        {
            const vector<int> *vec = &p.second;
            int size = vec->size();
            if (size < 2)
            {
                continue;
            }

            for (int i = 0; i < size; ++i)
            {
                for (int j = i + 1; j < size; ++j)
                {
                    if ((vec->at(i) * vec->at(j) % k) == 0)
                    {
                        ++res;
                    }
                }
            }
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

    cout << "请输入数组（格式如[3,1,2,2,2,1,3]）: ";
    getline(cin, input);

    cout << "请输入k的值: ";
    cin >> k;

    vector<int> nums = parseArray(input);
    if (nums.empty())
    {
        return 1;
    }

    int result = solution.countPairs(nums, k);
    cout << "满足条件的数对数量为: " << result << endl;

    // 测试用例1
    vector<int> test1 = {3, 1, 2, 2, 2, 1, 3};
    int k1 = 2;
    int res1 = solution.countPairs(test1, k1);
    cout << "\n测试用例1 ([3,1,2,2,2,1,3], k=2): " << res1 << endl;

    // 测试用例2
    vector<int> test2 = {1, 2, 3, 4};
    int k2 = 1;
    int res2 = solution.countPairs(test2, k2);
    cout << "测试用例2 ([1,2,3,4], k=1): " << res2 << endl;

    return 0;
}