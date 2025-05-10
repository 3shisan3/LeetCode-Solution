#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int note = 0;
        for (const int &val : arr)
        {
            note = val % 2 == 0 ? 0 : ++note;
            if (note == 3)
            {
                return true;
            }
        }
        return false;
    }
};

vector<int> parseInputArray()
{
    vector<int> arr;
    string input;

    cout << "请输入整数数组（用空格分隔，例如：1 2 3 5 7）：";
    getline(cin, input);

    istringstream iss(input);
    int num;
    while (iss >> num)
    {
        arr.push_back(num);
    }

    return arr;
}

void printResult(const vector<int> &arr, bool result)
{
    cout << "\n测试结果：" << endl;
    cout << "输入数组: [";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (i != 0)
            cout << ", ";
        cout << arr[i];
    }
    cout << "]" << endl;

    cout << "是否存在三个连续奇数: " << (result ? "是" : "否") << endl;
}

int main()
{
    Solution solution;

    cout << "=== 连续奇数检测 ===" << endl;
    cout << "（输入q退出程序）" << endl;

    while (true)
    {
        vector<int> arr = parseInputArray();
        if (arr.empty())
        {
            cout << "数组不能为空，请重新输入！" << endl;
            continue;
        }

        bool result = solution.threeConsecutiveOdds(arr);
        printResult(arr, result);

        cout << "\n是否继续测试？(y/n): ";
        string choice;
        getline(cin, choice);

        if (choice == "n" || choice == "N" || choice == "q")
        {
            break;
        }
    }

    return 0;
}