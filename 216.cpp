class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int num = 0;
        int flag = 0;
        caculate(k,n,flag,ans,tmp,num);
        return ans;
    }
    void caculate(int k,int n,int flag,vector<vector<int>> &ans,vector<int> &tmp,int num)
    {
        if(n == 0 && num == k)
        {
            ans.push_back(tmp);
            return;
        }
        if(num > k)
        {
            return;
        }
        for(int i = flag;i < 10;i++)
        {
            if(flag == i)
            {
                continue;
            }
            tmp.push_back(i);
            caculate(k,n-i,i,ans,tmp,num + 1);
            tmp.pop_back();
        }
    }
};
