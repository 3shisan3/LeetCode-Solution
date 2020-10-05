class Solution 
{
private:
    vector<vector<int>> ans;
    vector<int> myNums, subans;
    int tar, numSize;
    void DFS(int low, int sum)
    {
        if (sum == tar && subans.size() == 4)
        {
            ans.emplace_back(subans);
            return;
        }
        for (int i = low; i < numSize; ++i)
        {
            if (numSize - i < int(4 - subans.size())) //剪枝
                return;
            if (i > low && myNums[i] == myNums[i - 1]) //去重
                continue; 
            if (i < numSize - 1 && sum + myNums[i] + int(3 - subans.size()) * myNums[i + 1] > tar) //剪枝
                return;
            if (i < numSize - 1 && sum + myNums[i] + int(3 - subans.size()) * myNums[numSize - 1] < tar) //剪枝
                continue;
            subans.emplace_back(myNums[i]);
            DFS(i + 1, myNums[i] + sum);
            subans.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        myNums = nums;
        tar = target;
        numSize = nums.size();
        if (numSize < 4)
            return ans;
        DFS(0, 0);
        return ans;    
    }
};
