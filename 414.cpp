class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = -2147483649;
        long second = -2147483649;
        long third = -2147483649;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > first)
            {
                third = second;
                second = first;
                first = nums[i];
            }
            else if(nums[i] > second && nums[i] < first)
            {
                third = second;
                second = nums[i];
            }
            else if(nums[i] > third && nums[i] < second)
            {
                third = nums[i];
            }
        }
//        if(nums.size() < 3)
//        {
//            return first;
//        }
//        else
//        {
//            return third;
//        }
        return third == -2147483649 ? first : third;            
    }
};
