#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int percentageLetter(string s, char letter)
    {
        int num = std::count(s.begin(), s.end(), letter);

        int res = num != 0 ? num * 100 / s.size() : 0;

        return res;
    }
};

int main()
{
    Solution solution;
    string inputString;
    char letter;

    cout << "Enter the input string: ";
    getline(cin, inputString);

    cout << "Enter the letter to count: ";
    cin >> letter;

    int result = solution.percentageLetter(inputString, letter);
    cout << "Percentage of '" << letter << "' in \"" << inputString << "\": " << result << "%" << endl;

    return 0;
}