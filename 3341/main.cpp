#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>

using namespace std;

class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        const int INF = 0x3f3f3f3f;
        const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INF));
        queue<array<int, 2>> q;
        q.push({0, 0});
        dist[0][0] = 0;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int x = cur[0], y = cur[1];
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && dist[nx][ny] > max(dist[x][y], moveTime[nx][ny]) + 1)
                {
                    dist[nx][ny] = max(dist[x][y], moveTime[nx][ny]) + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};

vector<vector<int>> parseInputMatrix()
{
    vector<vector<int>> matrix;
    string input;

    cout << "请输入矩阵（每行用分号分隔，元素用空格分隔）：\n";
    cout << "示例：1 2 3;4 5 6;7 8 9\n";
    getline(cin, input);

    istringstream iss(input);
    string row;
    while (getline(iss, row, ';'))
    {
        istringstream row_ss(row);
        vector<int> row_vec;
        int num;
        while (row_ss >> num)
        {
            row_vec.push_back(num);
        }
        matrix.push_back(row_vec);
    }

    return matrix;
}

void printResult(int result)
{
    cout << "\n到达右下角的最小时间: " << result << endl;
}

int main()
{
    Solution solution;

    cout << "=== 矩阵最小到达时间计算 ===" << endl;
    cout << "（输入q退出）" << endl;

    while (true)
    {
        vector<vector<int>> matrix = parseInputMatrix();
        if (matrix.empty())
        {
            cout << "输入无效，请重新输入！" << endl;
            continue;
        }

        int result = solution.minTimeToReach(matrix);
        printResult(result);

        cout << "\n继续测试？(y/n): ";
        string choice;
        getline(cin, choice);
        if (choice == "n" || choice == "N" || choice == "q")
            break;
    }

    return 0;
}