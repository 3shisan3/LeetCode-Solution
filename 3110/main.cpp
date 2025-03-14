#include <iostream>
#include <string>
#include <cstdlib> // for abs()

using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    {
        int score = 0;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            score += abs(s[i] - s[i + 1]);
        }
        return score;
    }
};

int main()
{
    Solution solution;
    string input;

    cout << "Enter a string to calculate its score (or 'exit' to quit): ";
    while (cin >> input)
    {
        if (input == "exit")
        {
            break;
        }

        int score = solution.scoreOfString(input);
        cout << "The score of the string \"" << input << "\" is: " << score << endl;

        cout << "Enter another string (or 'exit' to quit): ";
    }

    cout << "Exiting the program. Goodbye!" << endl;
    return 0;
}