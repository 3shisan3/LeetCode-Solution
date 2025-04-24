#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>

using namespace std;

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        set<int> note(nums.begin(), nums.end());
        int typeNum = note.size();
        int n = nums.size();

        int res = 0;
        map<int, int> noteNum;
        int leftIndex = 0, rightIndex = -1;
        while (rightIndex < n)
        {
            int i = rightIndex;
            while (noteNum.size() < typeNum)
            {
                i++;
                if (i == n)
                {
                    return res;
                }
                noteNum[nums[i]]++;
            }
            rightIndex = i;
            res += n - rightIndex;

            noteNum[nums[leftIndex]]--;
            if (noteNum[nums[leftIndex]] == 0)
            {
                noteNum.erase(nums[leftIndex]);
            }
            leftIndex++;
        }

        return res;
    }
};

vector<int> parseInputArray()
{
    vector<int> nums;
    string input;

    cout << "请输入整数数组（用空格分隔，例如：1 3 1 2 2）: ";
    getline(cin, input);

    istringstream iss(input);
    int num;
    while (iss >> num)
    {
        nums.push_back(num);
    }

    return nums;
}

int main()
{
    Solution solution;

    while (true)
    {
        cout << "\n=== 测试 countCompleteSubarrays ===" << endl;
        vector<int> nums = parseInputArray();

        if (nums.empty())
        {
            cout << "输入为空，请重新输入！" << endl;
            continue;
        }

        int result = solution.countCompleteSubarrays(nums);
        cout << "完全子数组的数量: " << result << endl;

        cout << "\n是否继续测试？(y/n): ";
        char choice;
        cin >> choice;
        cin.ignore(); // 清除输入缓冲区

        if (tolower(choice) != 'y')
        {
            break;
        }
    }

    return 0;
}