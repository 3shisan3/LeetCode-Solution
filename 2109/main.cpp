#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        string res = "";

        size_t index = 0;
        size_t dealIndex = 0;
        for (const char c : s)
        {
            if (dealIndex < spaces.size() && index == static_cast<size_t>(spaces[dealIndex]))
            {
                res.push_back(' ');
                dealIndex++;
            }
            res.push_back(c);
            index++;
        }

        return res;
    }
};

int main()
{
    Solution solution;
    string inputString;
    vector<int> spaces;
    string line;

    cout << "Enter the input string: ";
    getline(cin, inputString);

    cout << "Enter the spaces positions separated by spaces (e.g., '0 1 2'): ";
    getline(cin, line);
    istringstream iss(line);
    int num;
    while (iss >> num)
    {
        spaces.push_back(num);
    }

    string result = solution.addSpaces(inputString, spaces);
    cout << "Result: \"" << result << "\"" << endl;

    return 0;
}