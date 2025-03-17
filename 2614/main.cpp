#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPrime(int n)
    {
        // 小于等于1的数不是质数
        if (n <= 1)
        {
            return false;
        }

        // 检查从2到sqrt(n)的数是否能整除n
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int diagonalPrime(vector<vector<int>> &nums)
    {
        int len = nums.size();

        int res = 0;
        for (int i = 0; i < len; ++i)
        {
            if (isPrime(nums[i][i]))
            {
                res = res > nums[i][i] ? res : nums[i][i];
            }
            if (isPrime(nums[i][len - i - 1]))
            {
                res = res > nums[i][len - i - 1] ? res : nums[i][len - i - 1];
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    int n;

    cout << "Enter the size of the square matrix (n x n): ";
    cin >> n;

    vector<vector<int>> nums(n, vector<int>(n));

    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> nums[i][j];
        }
    }

    int result = solution.diagonalPrime(nums);
    cout << "The largest prime number on the diagonals is: " << result << endl;

    return 0;
}