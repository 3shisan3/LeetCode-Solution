#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>

/* 微调 3341 题解超时 */
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
                int costTime = (nx + ny) % 2 == 0 ? 2 : 1;
                if (0 <= nx && nx < n && 0 <= ny && ny < m &&
                    dist[nx][ny] > max(dist[x][y], moveTime[nx][ny]) + costTime)
                {
                    dist[nx][ny] = max(dist[x][y], moveTime[nx][ny]) + costTime;
                    q.push({nx, ny});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};

/* 
作者：灵茶山艾府
链接：https://leetcode.cn/problems/find-minimum-time-to-reach-last-room-ii/solutions/2975554/dijkstra-zui-duan-lu-pythonjavacgo-by-en-alms/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);
        while (true) {
            auto [d, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == m - 1) {
                return d;
            }
            if (d > dis[i][j]) {
                continue;
            }
            int time = (i + j) % 2 + 1;
            for (auto& q : dirs) {
                int x = i + q[0], y = j + q[1];
                if (0 <= x && x < n && 0 <= y && y < m) {
                    int new_dis = max(d, moveTime[x][y]) + time;
                    if (new_dis < dis[x][y]) {
                        dis[x][y] = new_dis;
                        pq.emplace(new_dis, x, y);
                    }
                }
            }
        }
    }
};

