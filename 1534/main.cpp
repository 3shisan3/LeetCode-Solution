#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib> // for abs()

using namespace std;

class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int num = arr.size();
        // 简单题，暴力快速过，speed sleep
        int res = 0;
        for (int i = 0; i < num - 2; ++i)
        {
            for (int j = i + 1; j < num - 1; ++j)
            {
                for (int k = j + 1; k < num; ++k)
                {
                    if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c)
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
    int a, b, c;

    cout << "请输入数组（格式如[3,0,1,1,9,7]）: ";
    getline(cin, input);

    cout << "请输入a的值: ";
    cin >> a;

    cout << "请输入b的值: ";
    cin >> b;

    cout << "请输入c的值: ";
    cin >> c;

    vector<int> arr = parseArray(input);
    if (arr.empty())
    {
        return 1;
    }

    int result = solution.countGoodTriplets(arr, a, b, c);
    cout << "好三元组的数量为: " << result << endl;

    return 0;
}