#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int length = nums.size();
        int ptr = 0;

        for (int i = 1; i < length; i++)
        {
            if (nums[i] != nums[ptr])
            {
                ptr++;
                nums[ptr] = nums[i];
            }
        }
        return ptr + 1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    int input;

    cout << "Enter numbers (enter -1 to finish input): ";
    while (cin >> input)
    {
        if (input == -1)
        {
            break;
        }
        nums.push_back(input);
    }

    cout << "Original array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    int newLength = solution.removeDuplicates(nums);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "New length of the array: " << newLength << endl;

    return 0;
}