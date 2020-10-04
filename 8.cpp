class Solution {
public:
    int myAtoi(string s) {

        int flag1 = 0;
        int flag2 = 0;
        int zf = 1;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                continue;
            }
            if(s[i] == '-')
            {
                flag1 = i;
                zf = -1;
                break;
            }
            else if(s[i] == '+')
            {
                flag1 = i;
                break;
            }
            else /*if(s[i] <= '9' && s[i] >= '0')*/
            {
                flag1 = i;
                break;
            }
        }
        for(int i = flag1 + 1; i < s.size(); i++)
        {
            if(s[i] > '9' || s[i] < '0')
            {
                flag2 = i - 1;
                break;
            }
            if(i == s.size() - 1)
            {
                flag2 = i;
            }
        }

        long ans = 0;
        
        for(int i = flag1; i <= flag2; i++)
        {
            if(s[i] == '-' || s[i] == '+')
            {
                continue;
            }
            if(s[i] > '9' || s[i] < '0')
            {
                break;
            }
            ans += (s[i] - '0');
            ans *= 10;

            if(ans / 10 * zf > INT_MAX)
            {
                return INT_MAX;
            }
            if(ans / 10 * zf < INT_MIN)
            {
                return INT_MIN;
            }
        }

        ans = ans / 10 * zf;

        return (int)ans;
    }
};
