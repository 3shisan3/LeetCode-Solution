#include <algorithm> 
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int countOfSubstrings(string word, int k)
    {
        auto getBinaryValue = [](const char key) -> int
        {
            if (key == 'a')
            {
                return 0b10000;
            }
            else if (key == 'e')
            {
                return 0b01000;
            }
            else if (key == 'i')
            {
                return 0b00100;
            }
            else if (key == 'o')
            {
                return 0b00010;
            }
            else if (key == 'u')
            {
                return 0b00001;
            }
            return 0b00000;
        };

        int checkV = 0b00000;
        int res = 0;
        int curV = 0b00000;
        int num = 0;
        for (int i = 0; i < word.size(); ++i)
        {
            num = 0;
            checkV = 0b00000;

            for (int j = i; j < word.size(); ++j)
            {
                curV = getBinaryValue(word[j]);
                if (curV == 0b00000)
                {
                    num++;
                }

                checkV |= curV;
                if (checkV == 0b11111 && num == k)
                {
                    res++;
                }

                if (num > k)
                {
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;

    // 读取输入的字符串和k值
    string word;
    int k;
    cout << "请输入字符串: ";
    cin >> word;
    cout << "请输入k值: ";
    cin >> k;

    // 调用函数并输出结果
    int result = solution.countOfSubstrings(word, k);
    cout << "符合条件的子串数量为: " << result << endl;

    return 0;
}