#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        int strlen = k;
        while (pow(10, strlen) <= num)
        {
            strlen++;
        }

        int res = 0;
        int curValue;
        for (int i = 0; i <= strlen - k; ++i)
        {
            int tmp = num / (pow(10, strlen - i)); // 自动去尾
            int leftDis = tmp * pow(10, strlen - i);

            curValue = (num - leftDis) / pow(10, strlen - k - i);

            if (curValue != 0 && num % curValue == 0)
            {
                res++;
            }
        }

        return res;
    }
};

int main()
{
    int num, k;
    cout << "输入num和k的值（输入负数退出）: ";

    while (cin >> num >> k)
    {
        if (num < 0 || k < 0)
        {
            cout << "程序已退出。" << endl;
            break;
        }

        Solution solution;
        int result = solution.divisorSubstrings(num, k);

        cout << "num = " << num << ", k = " << k << " 的结果是: " << result << endl;
        cout << "\n输入下一个num和k的值（负数退出）: ";
    }

    return 0;
}
