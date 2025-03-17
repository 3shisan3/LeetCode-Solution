#include <iostream>
#include <string>
#include <algorithm> // for min()

using namespace std;

class Solution
{
public:
    int minSwaps(string s)
    {
        int cnt = 0, mincnt = 0;
        for (char ch : s)
        {
            if (ch == '[')
            {
                cnt += 1;
            }
            else
            {
                cnt -= 1;
                mincnt = min(mincnt, cnt);
            }
        }
        return (-mincnt + 1) / 2;
    }
};

int main()
{
    Solution solution;
    string input;

    cout << "Enter a string consisting of '[' and ']' (or 'exit' to quit): ";
    while (cin >> input)
    {
        if (input == "exit")
        {
            break;
        }

        int swaps = solution.minSwaps(input);
        cout << "Minimum swaps required for the string \"" << input << "\": " << swaps << endl;

        cout << "Enter another string (or 'exit' to quit): ";
    }

    cout << "Exiting the program. Goodbye!" << endl;
    return 0;
}