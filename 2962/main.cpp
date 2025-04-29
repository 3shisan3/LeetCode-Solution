#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxVal = 0;
        vector<int> maxVal_index;

        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (maxVal < nums[i])
            {
                maxVal_index.clear();
                maxVal = nums[i];
                maxVal_index.emplace_back(i);
            }
            else if (maxVal == nums[i])
            {
                maxVal_index.emplace_back(i);
            }
        }

        maxVal_index.emplace(maxVal_index.begin(), -1);
        long long res = 0;
        int left = 1, right = k;
        while (right < maxVal_index.size())
        {
            res += (long long)(maxVal_index[left] - maxVal_index[left - 1]) *
                   (n - maxVal_index[right]);
            left++;
            right++;
        }

        return res;
    }
};

vector<int> getInputArray()
{
    vector<int> nums;
    string line;

    cout << "输入整数数组（空格分隔）：";
    getline(cin, line);
    istringstream iss(line);

    int num;
    while (iss >> num)
    {
        nums.push_back(num);
    }
    return nums;
}

int getInputK()
{
    int k;
    cout << "输入k值：";
    cin >> k;
    return k;
}

void runTest()
{
    Solution solution;
    while (true)
    {
        vector<int> nums = getInputArray();
        if (nums.empty())
        {
            cout << "数组不能为空！" << endl;
            continue;
        }

        int k = getInputK();
        cin.ignore(); // 清除输入缓冲区

        long long result = solution.countSubarrays(nums, k);
        cout << "结果：" << result << endl
             << endl;

        cout << "继续测试？(y/n): ";
        char choice;
        cin >> choice;
        cin.ignore();

        if (tolower(choice) != 'y')
            break;
    }
}

int main()
{
    runTest();
    return 0;
}


/* 
恰好k次的子数组数
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxVal = 0;
        vector<int> maxVal_index;

        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (maxVal < nums[i])
            {
                maxVal_index.clear();
                maxVal = nums[i];
                maxVal_index.emplace_back(i);
            }
            else if (maxVal == nums[i])
            {
                maxVal_index.emplace_back(i);
            }
        }

        long long res = 0;
        if (k > maxVal_index.size())
        {
            return res;
        }
        else if (k == maxVal_index.size())
        {
            return (maxVal_index[0] + 1) * (n - maxVal_index[k - 1]);
        }
        else
        {
            res += (maxVal_index[0] + 1) * (maxVal_index[k - 1] - maxVal_index[k - 2]);
        }
        int i = 1;
        for (; i + k < maxVal_index.size(); i++)
        {
            res += (maxVal_index[i] - maxVal_index[i - 1]) *
                   (maxVal_index[i + k - 1] - maxVal_index[i + k - 2]);
        }
        res += (maxVal_index[i] - maxVal_index[i - 1]) *
               (n - maxVal_index[i + k - 1]);

        return res;
    }
};
*/