#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        // 隐藏数组，第一个数的取值范围
        int minVal = lower;
        int maxVal = upper;
        // 通过累加，可得到隐藏数组中每个数减第一个数的值
        int curDiff = 0;
        for (int diff : differences)
        {
            curDiff += diff;

            minVal = lower - curDiff > minVal ? lower - curDiff : minVal;
            maxVal = upper - curDiff < maxVal ? upper - curDiff : maxVal;

            if (maxVal < minVal)
            {
                return 0;
            }
        }

        return maxVal - minVal + 1;
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
    int lower, upper;

    cout << "请输入差值数组（格式如[1,-3,4]）: ";
    getline(cin, input);

    cout << "请输入lower的值: ";
    cin >> lower;

    cout << "请输入upper的值: ";
    cin >> upper;

    vector<int> differences = parseArray(input);
    if (differences.empty())
    {
        return 1;
    }

    int result = solution.numberOfArrays(differences, lower, upper);
    cout << "可能的隐藏数组数量为: " << result << endl;

    return 0;
}