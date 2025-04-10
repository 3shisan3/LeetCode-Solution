#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        auto dealFunc = [](int val) -> bool
        {
            string val_str = to_string(val);

            if (val_str.size() % 2 != 0)
            {
                return false;
            }

            int left = 0, right = val_str.size() - 1;
            int leftSum = 0, rightSum = 0;
            while (left < right)
            {
                leftSum += val_str[left];
                rightSum += val_str[right];

                left++;
                right--;
            }

            return leftSum == rightSum;
        };

        int res = 0;
        for (int i = low; i <= high; ++i)
        {
            if (dealFunc(i))
            {
                res++;
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    int low, high;

    cout << "请输入下限 low: ";
    cin >> low;

    cout << "请输入上限 high: ";
    cin >> high;

    if (low > high)
    {
        cout << "错误：下限不能大于上限" << endl;
        return 1;
    }

    int result = solution.countSymmetricIntegers(low, high);
    cout << "在 [" << low << ", " << high << "] 范围内的对称整数数量为: " << result << endl;

    return 0;
}