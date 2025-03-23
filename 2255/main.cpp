#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int countPrefixes(vector<string> &words, string s)
    {
        int i = 0;
        int compareMaxLen = s.size();

        int res = 0;
        for (const auto &word : words)
        {
            while (i < word.size() && i < compareMaxLen && word[i] == s[i])
            {
                i++;
            }

            if (i == word.size())
            {
                res++;
            }
            i = 0;
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<string> words;
    string s, input;

    cout << "Enter words (enter 'done' to finish input): ";
    while (cin >> input)
    {
        if (input == "done")
        {
            break;
        }
        words.push_back(input);
    }

    cout << "Enter the string s: ";
    cin >> s;

    int result = solution.countPrefixes(words, s);

    cout << "The number of prefixes of \"" << s << "\" in the words list is: " << result << endl;

    return 0;
}