class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int sum;
        string ans = "";
        sum = accumulate(digits.begin(),digits.end(),0);
        if(sum == 0)
        {
            ans = "0";
        }
        else
        {
            if(sum % 3 != 0)
            {
                vector<int> yuone,yutwo;
                sort(digits.begin(),digits.end());
                for(int i = 0; i < digits.size(); i++)
                {
                    if(digits[i] % 3 == 1 && yuone.size() < 2)
                    {
                        yuone.emplace_back(i);
                    }
                    if(digits[i] % 3 == 2 && yutwo.size() < 2)
                    {
                        yutwo.emplace_back(i);
                    }
                }
                if(sum % 3 == 1)
                {
                    if(yuone.size() >= 1 && digits.size() > 1)
                    {
                        digits.erase(digits.begin() + yuone[0]);
                    }
                    else if(yutwo.size() >= 2 && digits.size() > 2)
                    {
                        digits.erase(digits.begin() + yutwo[0]);
                        digits.erase(digits.begin() + yutwo[1] - 1);
                    }
                    else
                    {
                        return ans;
                    }
                }
                //得到一个去除数据后的新digits
                if(sum % 3 == 2)
                {
                    if(yutwo.size() >= 1 && digits.size() > 1)
                    {
                        digits.erase(digits.begin() + yutwo[0]);
                    }
                    else if(yuone.size() >= 2 && digits.size() > 2)
                    {
                        digits.erase(digits.begin() + yuone[0]);
                        digits.erase(digits.begin() + yuone[1] - 1);
                    }
                    else
                    {
                        return ans;
                    }
                }
            }
            
            sort(digits.begin(), digits.end(), greater<int>());
            for(int i = 0; i < digits.size(); i++)
            {
                ans += static_cast<char>(digits[i] + 48);
            }                         
        }

        return ans;
    }

};
