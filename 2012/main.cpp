#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution
{
public:
    int sumOfBeauties(vector<int> &nums)
    {
        int leftMaxValue = nums[0]; // 题目描述“所有”
        int rightDecreaseIndex = 1; // 数组中开始递减下标
        while (rightDecreaseIndex < nums.size() &&
               nums[rightDecreaseIndex] > nums[rightDecreaseIndex - 1])
        {
            rightDecreaseIndex++;
        }
        int rightMinValueIndex = rightDecreaseIndex;
        for (int j = rightMinValueIndex + 1; j < nums.size(); j++)
        {
            if (nums[rightMinValueIndex] > nums[j])
            {
                rightMinValueIndex = j;
            }
        }

        int result = 0;
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            if (rightDecreaseIndex == nums.size()) // 后续为递增（有序）数组
            {
                if (leftMaxValue < nums[i])
                {
                    result += 2;
                }
                else if (nums[i - 1] < nums[i])
                {
                    result += 1;
                }
                else
                {
                    result += 0; // 方便理解代码逻辑
                }
                continue;
            }

            if (i >= rightDecreaseIndex || i >= rightMinValueIndex)
            {
                // 更新rightDecreaseIndex 和 rightMinValueIndex
                rightDecreaseIndex = i;
                while (rightDecreaseIndex < nums.size() &&
                       nums[rightDecreaseIndex] > nums[rightDecreaseIndex - 1])
                {
                    rightDecreaseIndex++;
                }
                for (int j = rightDecreaseIndex; j < nums.size(); j++)
                {
                    if (nums[rightMinValueIndex] > nums[j])
                    {
                        rightMinValueIndex = j;
                    }
                }
            }

            if (leftMaxValue < nums[i] && nums[i] < nums[rightMinValueIndex])
            {
                result += 2;
                leftMaxValue = nums[i];
                continue;
            }

            if (leftMaxValue < nums[i])
            {
                leftMaxValue = nums[i];
            }

            if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
            {
                result += 1;
            }
            else
            {
                result += 0;
            }
        }

        return result;
    }
};

int main()
{
    cout << "输入数组元素（用逗号分隔，输入负数退出）: ";
    string input;

    while (getline(cin, input))
    { // 读取整行输入
        if (input.empty())
        {
            cout << "输入为空，请重新输入: ";
            continue;
        }

        // 检查是否输入负数退出
        stringstream ss(input);
        int firstNumber;
        ss >> firstNumber;
        if (firstNumber < 0)
        {
            cout << "程序已退出。" << endl;
            break;
        }

        // 解析逗号分隔的数组元素
        vector<int> nums;
        stringstream ss2(input);
        string token;
        while (getline(ss2, token, ','))
        {                                // 按逗号分隔
            nums.push_back(stoi(token)); // 将字符串转换为整数
        }

        Solution solution;
        int result = solution.sumOfBeauties(nums);

        cout << "数组的美丽值总和是: " << result << endl;
        cout << "\n输入下一个数组元素（用逗号分隔，输入负数退出）: ";
    }

    return 0;
}

// 省时方法二：申请两个数组，一个数组从左向右遍历，记录当前下标映射的原数组该下标左边最大值
//                         一个数组从右向左遍历，记录当前下标映射的原数组该下标右边最小值
//            最后结合两数组下标值循环计算得到result(理论步骤，三次循环可省略为两次)