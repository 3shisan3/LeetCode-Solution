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


/* 滑动窗口思路，右指针移动 ，统计时先不限制非== k而采用 >= k 结合满足五个元音 以此扩容窗口并得到数量 ，
                左指针移动 ，记录元音类型触发减少时位置，锁定窗口   循环步骤遍历，同样On2的时间复杂度
                两个至少，最后用k - (k + 1)的形式得到结果
*/

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