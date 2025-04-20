#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        map<int, int> typeNote;

        int ans = 0;
        for (auto type : answers)
        {
            if (typeNote.find(type) == typeNote.end())
            {
                typeNote.insert({type, 1});
            }
            else
            {
                ++typeNote[type];
            }
        }

        for (auto note : typeNote)
        {
            int val = note.second % (note.first + 1);
            int val2 = note.second / (note.first + 1);
            int typeNum = val == 0 ? val2 : val2 + 1;

            ans += typeNum * (note.first + 1);
        }

        return ans;
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

    cout << "请输入兔子回答数组（格式如[1,1,2]）: ";
    getline(cin, input);

    vector<int> answers = parseArray(input);
    if (answers.empty())
    {
        return 1;
    }

    int result = solution.numRabbits(answers);
    cout << "森林中最少兔子的数量为: " << result << endl;

    return 0;
}