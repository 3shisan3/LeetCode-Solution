#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

class Solution
{
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        ranges::sort(tasks);
        ranges::sort(workers);
        int m = workers.size();

        auto check = [&](int k) -> bool
        {
            // 贪心：用最强的 k 名工人，完成最简单的 k 个任务
            int i = 0, p = pills;
            deque<int> valid_tasks;
            for (int j = m - k; j < m; j++)
            { // 枚举工人
                int w = workers[j];
                // 在吃药的情况下，把能完成的任务记录到 valid_tasks 中
                while (i < k && tasks[i] <= w + strength)
                {
                    valid_tasks.push_back(tasks[i]);
                    i++;
                }
                // 即使吃药也无法完成任务
                if (valid_tasks.empty())
                {
                    return false;
                }
                // 无需吃药就能完成（最简单的）任务
                if (w >= valid_tasks.front())
                {
                    valid_tasks.pop_front();
                    continue;
                }
                // 必须吃药
                if (p == 0)
                { // 没药了
                    return false;
                }
                p--;
                // 完成（能完成的）最难的任务
                valid_tasks.pop_back();
            }
            return true;
        };

        int left = 0, right = min((int)tasks.size(), m) + 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            (check(mid) ? left : right) = mid;
        }
        return left;
    }
};

/* 初版，但中间重叠过滤部分逻辑还需梳理

class Solution
{
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int taskLeft = 0, workerLeft = 0;
        int num = workers.size();
        int taskMaxRight = tasks.size() - 1;
        while (workers.back() + strength < tasks[taskMaxRight])
        {
            taskMaxRight--;
        }

        workerLeft += (num - taskMaxRight - 1 <= 0 ? 0 : num - taskMaxRight - 1);

        int res = 0;
        while (workerLeft < num)
        {
            if (tasks[taskLeft] <= workers[workerLeft])
            {
                res++;

                workerLeft++;
                taskLeft++;
            }
            else if (tasks[taskLeft] <= workers[workerLeft] + strength)
            {
                int tempIndex = workerLeft + 1;
                while (tempIndex < num && workers[tempIndex] < tasks[taskLeft])
                {
                    tempIndex++;
                }
                // 此场景还需补充逻辑
                workerLeft = (tempIndex - pills > workerLeft ? tempIndex - pills : workerLeft);
                res++;

                workerLeft++;
                taskLeft++;
            }
            else
            {
                workerLeft++;
            }
        }

        return res;
    }
};
*/
