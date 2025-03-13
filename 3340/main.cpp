#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isBalanced(string num)
    {
        bool isEven = true;
        int calVal = 0;
        for (char v : num)
        {
            int curVal = v - '0';
            calVal = isEven ? (curVal + calVal) : (calVal - curVal);
            isEven = !isEven;
        }
        return calVal == 0;
    }
};

int main()
{
    Solution solution;
    string input;

    cout << "Enter a number to check if it is balanced (or 'exit' to quit): ";
    while (cin >> input)
    {
        if (input == "exit")
        {
            break;
        }

        bool result = solution.isBalanced(input);
        cout << "The number \"" << input << "\" is "
             << (result ? "balanced" : "not balanced") << "." << endl;

        cout << "Enter another number (or 'exit' to quit): ";
    }

    cout << "Exiting the program. Goodbye!" << endl;
    return 0;
}