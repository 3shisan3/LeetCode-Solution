#include <iostream>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> numsTypes;

        for (const auto &val : nums)
        {
            numsTypes.insert(val);
        }

        int minVal = *numsTypes.begin();
        
        if (minVal < k)
        {
            return -1;
        }
        else if (minVal == k)
        {
            return numsTypes.size() - 1;
        }
        return numsTypes.size();
    }
};

vector<int> parseInputArray(const string& input) {
    vector<int> nums;
    stringstream ss(input);
    char ch;
    int num;

    // 验证并跳过开头的'['
    ss >> ch;
    if (ch != '[') {
        cerr << "错误：输入应以'['开头" << endl;
        return nums;
    }
    
    // 读取数字直到遇到']'
    while (ss >> num) {
        nums.push_back(num);
        ss >> ch;
        if (ch == ']') break;
        if (ch != ',') {
            cerr << "错误：数字之间应以逗号分隔" << endl;
            return vector<int>();
        }
    }

    if (ch != ']') {
        cerr << "错误：输入应以']'结尾" << endl;
        return vector<int>();
    }

    return nums;
}

int main() {
    Solution solution;
    string input;
    int k;

    cout << "请输入整数数组（格式如[1,2,3,4,5]）：";
    getline(cin, input);

    cout << "请输入目标k值：";
    cin >> k;

    vector<int> nums = parseInputArray(input);
    if (nums.empty()) {
        return 1;
    }

    int result = solution.minOperations(nums, k);
    cout << "最小操作次数为: " << result << endl;

    return 0;
}

/*
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> numsTypes;

        for (const auto &val : nums)
        {
            if (val == k)
            {
                continue;
            }
            else if (val < k)
            {
                return -1;
            }
            numsTypes.insert(val);
        }
        
        return numsTypes.size();
    }
};
*/
