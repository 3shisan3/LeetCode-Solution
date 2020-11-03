class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3)
        {
            return false;
        }
        int max = 0;
        //寻找数组中最大值的下标
        for(int i = 1; i < A.size(); i++)
        {
            if(A[i] > A[i - 1])
            {
                max = i;
            }
            if(A[i] == A[i - 1])
            {
                return false;
            }
        }
        if(max == 0 || max == A.size() -1)
        {
            return false;
        }
        for(int i = 0; i < max - 1; i++)
        {
            if(A[i + 1] < A[i])
            {
                return false;
            }
        }
        for(int i = max; i < A.size()-1; i++)
        {
            if(A[i] < A[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};
