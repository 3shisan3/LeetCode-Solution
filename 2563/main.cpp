#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long res = 0;
        int left = n, right = n;
        for (int j = 0; j < nums.size(); ++j)
        {
            while (right && nums[right - 1] > upper - nums[j])
            {
                right--;
            }
            while (left && nums[left - 1] >= lower - nums[j])
            {
                left--;
            }
            res += min(right, j) - min(left, j);
        }

        return res;
    }
};

/* // 最初超时版本
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long res = 0;
        int left = 0, right = n - 1;
        int noteLastRight = n - 1, noteLastLeft = n;
        while (left < right)
        {
            if (nums[left] + nums[right] > upper)
            {
                right--;
            }
            else if (nums[left] + nums[right] < lower)
            {
                left++;
                right = noteLastRight;
            }
            else if (noteLastLeft == left)
            {
                res++;
                right--;
                if (left == right)
                {
                    left++;
                    right = noteLastRight;
                }
            }
            else
            {
                res++;
                noteLastRight = right;
                noteLastLeft = left;
                right--;
            }
        }

        return res;
    }
};
*/

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
    int lower, upper;

    cout << "请输入数组（格式如[0,1,7,4,4,5]）: ";
    getline(cin, input);

    cout << "请输入lower的值: ";
    cin >> lower;

    cout << "请输入upper的值: ";
    cin >> upper;

    vector<int> nums = parseArray(input);
    if (nums.empty())
    {
        return 1;
    }

    long long result = solution.countFairPairs(nums, lower, upper);
    cout << "公平数对的数量为: " << result << endl;

    return 0;
}