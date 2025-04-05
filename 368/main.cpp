#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
    public:
        void getSubset(int index, vector<int> &nums, vector<int> curSet, std::map<int, vector<int>> &allSubset)
        {
            if (!allSubset.empty())
            {
                vector<int> *curMaxSubset = &allSubset.rbegin()->second;
                if (curSet.size() + nums.size() - index < curMaxSubset->size())
                {
                    return;
                }
            }
    
            // 已知大小关系，只用确认 大 % 小
            if (curSet.empty() || nums[index] % curSet.back() == 0)
            {
                curSet.push_back(nums[index]);
            }
            if (index == nums.size() - 1)
            {
                allSubset.insert({curSet.size(), curSet});
                return;
            }
    
            for (int i = index + 1; i < nums.size(); ++i)
            {
                getSubset(i, nums, curSet, allSubset);
            }
        }
    
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            std::map<int, vector<int>> allSubset;   // key = vec.size()
    
            sort(nums.begin(), nums.end());         // 这样每次子集增加元素只用比较最后一个数
            
            for (int i = 0; i < nums.size(); ++i)
            {
                getSubset(i, nums, {}, allSubset);
            }
    
            return allSubset.rbegin()->second;
        }
    };

vector<int> parseInput(const string &input)
{
    vector<int> nums;
    stringstream ss(input);
    char ch;
    int num;

    // 跳过开头的'['
    ss >> ch;
    if (ch != '[')
    {
        cerr << "错误：输入应以'['开头" << endl;
        return nums;
    }

    // 读取数字直到遇到']'
    while (ss >> num)
    {
        nums.push_back(num);
        ss >> ch;
        if (ch == ']')
            break;
        if (ch != ',')
        {
            cerr << "错误：数字之间应以逗号分隔" << endl;
            return vector<int>();
        }
    }

    if (ch != ']')
    {
        cerr << "错误：输入应以']'结尾" << endl;
        return vector<int>();
    }

    return nums;
}

void printVector(const vector<int> &vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i];
        if (i != vec.size() - 1)
            cout << ",";
    }
    cout << "]";
}

int main()
{
    Solution solution;
    string input;

    cout << "请输入整数数组（格式如[1,2]）：";
    getline(cin, input);

    vector<int> nums = parseInput(input);
    if (nums.empty())
    {
        return 1;
    }

    vector<int> result = solution.largestDivisibleSubset(nums);
    cout << "最大可整分子集：";
    printVector(result);
    cout << endl;

    return 0;
}

/* 大数据时超时了，采用动态规划 */

/* 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> f(n, 0);
        vector<int> g(n ,0);
        
        for(int i = 0; i < n; i++) {
            // 至少包含自身一个数，因此起始长度为 1，由自身转移而来
            int len = 1, prev = i;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    // 如果能接在更长的序列后面，则更新「最大长度」&「从何转移而来」
                    if(f[j] + 1 > len) {
                        len = f[j] + 1;
                        prev = j;
                    }
                }
            }
            f[i] = len;
            g[i] = prev;
        }

        // 遍历所有的 f[i]，取得「最大长度」和「对应下标」
        int idx = max_element(f.begin(), f.end()) - f.begin();
        int max = f[idx];

        // 使用 g[] 数组回溯出具体方案
        vector<int> ans;
        while(ans.size() != max) {
            ans.push_back(nums[idx]);
            idx = g[idx];
        }
        return ans;
    }
};
*/