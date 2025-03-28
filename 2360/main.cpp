
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Solution
{
public:
    int longestCycle(vector<int> &edges)
    {
        vector<int> l;
        int ans = -1;

        for (int i = 0; i < edges.size(); ++i)
        {
            if (std::count(l.begin(), l.end(), i))
            {
                continue;
            }

            l.clear();
            l.push_back(i);

            int nextNode = edges[i];
            l.push_back(nextNode);

            while (nextNode != -1 && std::count(l.begin(), l.end(), nextNode) < 2)
            {
                nextNode = edges[nextNode];
                l.push_back(nextNode);
            }

            if (nextNode == -1)
            {
                continue;
            }
            auto index = find(l.begin(), l.end(), nextNode);
            ans = ans > (distance(index, l.end()) - 1) ? ans : (distance(index, l.end()) - 1);
        }

        return ans;
    }
};
// 超时

/* // 简单修改
class Solution
{
public:
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<bool> visited(n, false);
        int ans = -1;

        for (int i = 0; i < n; ++i)
        {
            if (visited[i] || edges[i] == -1)
                continue;

            unordered_set<int> currentPath;
            int node = i;
            int length = 0;

            while (node != -1)
            {
                if (currentPath.count(node))
                {
                    // Found a cycle
                    int cycleLength = 0;
                    int start = node;
                    int current = edges[start];
                    cycleLength = 1;

                    while (current != start)
                    {
                        current = edges[current];
                        cycleLength++;
                    }

                    ans = max(ans, cycleLength);
                    break;
                }

                if (visited[node])
                    break;

                visited[node] = true;
                currentPath.insert(node);
                node = edges[node];
                length++;
            }
        }

        return ans;
    }
}; */

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " \"[edge1,edge2,...]\"" << endl;
        cerr << "Example: " << argv[0] << " \"[3,3,4,2,3]\"" << endl;
        return 1;
    }

    string input = argv[1];
    vector<int> edges;

    // Remove brackets and parse the input
    input.erase(remove(input.begin(), input.end(), '['), input.end());
    input.erase(remove(input.begin(), input.end(), ']'), input.end());

    stringstream ss(input);
    string token;

    while (getline(ss, token, ','))
    {
        if (token.empty())
            continue;
        try
        {
            edges.push_back(stoi(token));
        }
        catch (const invalid_argument &e)
        {
            cerr << "Invalid input: " << token << " is not a valid integer." << endl;
            return 1;
        }
        catch (const out_of_range &e)
        {
            cerr << "Invalid input: " << token << " is out of range for an integer." << endl;
            return 1;
        }
    }

    Solution solution;
    int result = solution.longestCycle(edges);
    cout << "Longest cycle length: " << result << endl;

    return 0;
}