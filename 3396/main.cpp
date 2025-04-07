#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int n = nums.size();
        int leftIndex = 0, lastIndex = -1;
        for (int rightIndex = n - 1; rightIndex >= leftIndex; --rightIndex)
        {
            int curVal = nums[rightIndex];
            for (int i = leftIndex; i < rightIndex; ++i)
            {
                if (nums[i] == curVal)
                {
                    lastIndex = max(lastIndex, i);

                    leftIndex = lastIndex;
                }
            }
        }

        // +1 表示实际需要移除的元素数量，+2是为了除三向上取整
        return (lastIndex + 1 + 2) / 3;
    }
};

/* hash存入，一次遍历亦可
另上写法，内部循环也由右到左会更好
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int leftIndex = 0, lastIndex = -1;
        for (int rightIndex = n - 1; rightIndex >= leftIndex; --rightIndex)
        {
            int curVal = nums[rightIndex];
            for (int i = rightIndex - 1; i >= leftIndex; --i)
            {
                if (nums[i] == curVal)
                {
                    lastIndex = i;
                    leftIndex = lastIndex;
                    break;
                }
            }
        }

        // +1 表示需要移除的元素数量，+2是为了除三向上取整
        return (lastIndex + 1 + 2) / 3;
    }
};
*/

vector<int> parseInput(const string &input)
{
    vector<int> nums;
    stringstream ss(input);
    char ch;
    int num;

    // 跳过开头的'['
    ss >> ch;
    if (ch != '[')
    {
        cerr << "错误：输入应以'['开头" << endl;
        return nums;
    }

    // 读取数字直到遇到']'
    while (ss >> num)
    {
        nums.push_back(num);
        ss >> ch;
        if (ch == ']')
            break;
        if (ch != ',')
        {
            cerr << "错误：数字之间应以逗号分隔" << endl;
            return vector<int>();
        }
    }

    if (ch != ']')
    {
        cerr << "错误：输入应以']'结尾" << endl;
        return vector<int>();
    }

    return nums;
}

int main()
{
    Solution solution;
    string input;

    cout << "请输入整数数组（格式如[1,2,3,4,5]）：";
    getline(cin, input);

    vector<int> nums = parseInput(input);
    if (nums.empty())
    {
        return 1;
    }

    int result = solution.minimumOperations(nums);
    cout << "最小操作次数为: " << result << endl;

    return 0;
}