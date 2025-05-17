#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            nums[i] = 2;
            if (x <= 1) {
                nums[p1++] = 1;
            }
            if (x == 0) {
                nums[p0++] = 0;
            }
        }
    }
};

vector<int> parseInputArray() {
    vector<int> nums;
    string input;
    
    cout << "请输入数字数组（仅包含0、1、2，用空格分隔，例如：2 0 2 1 1 0）：";
    getline(cin, input);
    
    istringstream iss(input);
    int num;
    while (iss >> num) {
        if (num != 0 && num != 1 && num != 2) {
            cout << "错误：数字只能是0、1或2！" << endl;
            return {};
        }
        nums.push_back(num);
    }
    
    return nums;
}

void printArray(const vector<int>& nums, const string& label) {
    cout << label << ": [";
    for (size_t i =  ˝0; i < nums.size(); ++i) {
        if (i != 0) cout << ", ";
        cout << nums[i];
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    cout << "=== 颜色排序（荷兰国旗问题）===" << endl;
    cout << "（输入q退出程序）" << endl;
    
    while (true) {
        vector<int> nums = parseInputArray();
        if (nums.empty()) {
            continue;
        }
        
        vector<int> original = nums; // 保存原始数组用于显示
        
        solution.sortColors(nums);
        
        cout << "\n测试结果：" << endl;
        printArray(original, "原始数组");
        printArray(nums, "排序后数组");
        
        cout << "\n是否继续测试？(y/n): ";
        string choice;
        getline(cin, choice);
        
        if (choice == "n" || choice == "N" || choice == "q") {
            break;
        }
    }
    
    return 0;
}