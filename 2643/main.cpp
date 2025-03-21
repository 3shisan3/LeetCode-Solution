#include <iostream>
#include <vector>
#include <numeric> // for accumulate

using namespace std;

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        vector<int> res(2, 0);

        int lineNum = 0;
        for (const auto &vec : mat)
        {
            int sum = accumulate(vec.begin(), vec.end(), 0);
            if (res[1] < sum)
            {
                res[0] = lineNum;
                res[1] = sum;
            }
            lineNum++;
        }

        return res;
    }
};

int main()
{
    Solution solution;
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));

    cout << "Enter the matrix row by row:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> mat[i][j];
        }
    }

    vector<int> result = solution.rowAndMaximumOnes(mat);

    cout << "The row with the maximum number of 1s is: " << result[0] << endl;
    cout << "The number of 1s in this row is: " << result[1] << endl;

    return 0;
}