#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid)
    {
        int hangNum = grid.size();
        int lieNum = grid.front().size();

        int diagonalNum = hangNum > lieNum ? hangNum : lieNum;
        map<int, vector<int>> diagonalVec;

        for (int i = 0; i < hangNum; i++)
        {
            for (int j = 0; j < lieNum; j++)
            {
                diagonalVec[i - j].emplace_back(grid[i][j]);
            }
        }

        vector<vector<int>> res(hangNum, vector<int>(lieNum, 0));

        for (int i = 0; i < hangNum; i++) // 行
        {
            for (int j = 0; j < lieNum; j++) // 列
            {
                auto *temp = &diagonalVec[i - j];
                // 统计序号 index 的前后差值
                int index = i - j < 0 ? i : j;

                int before_num = 0;
                if (index > 0)
                {
                    std::unordered_set<int> before_set(temp->begin(), temp->begin() + index);
                    before_num = before_set.size();
                }

                int after_num = 0;
                if (index + 1 < temp->size())
                {
                    std::unordered_set<int> after_set(temp->begin() + index + 1, temp->end());
                    after_num = after_set.size();
                }

                res[i][j] = abs(after_num - before_num);
            }
        }

        return res;
    }
};

vector<vector<int>> parseInput(const string &input)
{
    vector<vector<int>> grid;
    stringstream ss(input);
    char ch;

    // 移除所有空格
    string noSpaces;
    for (char c : input)
    {
        if (!isspace(c))
        {
            noSpaces += c;
        }
    }
    ss.str(noSpaces);
    ss.clear();

    ss >> ch; // 读取第一个 '['

    while (true)
    {
        ss >> ch; // 读取 '[' 或 ']'
        if (ch == ']')
            break;

        vector<int> row;
        while (true)
        {
            int num;
            ss >> num;
            row.push_back(num);

            ss >> ch; // 读取 ',' 或 ']'
            if (ch == ']')
                break;
        }
        grid.push_back(row);

        ss >> ch; // 读取 ',' 或 ']'
        if (ch == ']')
            break;
    }

    return grid;
}

void printGrid(const vector<vector<int>> &grid)
{
    cout << "[";
    for (size_t i = 0; i < grid.size(); ++i)
    {
        if (i != 0)
            cout << ",";
        cout << "[";
        for (size_t j = 0; j < grid[i].size(); ++j)
        {
            if (j != 0)
                cout << ",";
            cout << grid[i][j];
        }
        cout << "]";
    }
    cout << "]" << endl;
}

int main()
{
    string input;
    cout << "请输入二维数组（格式如 [[1,2,3],[3,1,5],[3,2,1]]）: ";
    getline(cin, input); // 从命令行读取输入

    // 解析输入
    vector<vector<int>> grid;
    try
    {
        grid = parseInput(input);
    }
    catch (...)
    {
        cerr << "输入格式错误！请确保输入类似 [[1,2,3],[3,1,5],[3,2,1]] 的格式。" << endl;
        return 1;
    }

    cout << "\n输入网格：" << endl;
    printGrid(grid);

    // 调用函数计算
    Solution sol;
    vector<vector<int>> result = sol.differenceOfDistinctValues(grid);

    cout << "\n计算结果：" << endl;
    printGrid(result);

    return 0;
}