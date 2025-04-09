class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        typedef long long ll;

        reverse(s.begin(), s.end());
        ll dp[20];
        int a[20];

        auto dfs = [&](auto &&self, int pos, int limit_) -> ll
        {
            if (!pos)
            {
                return 1;
            }
            if (!limit_ && dp[pos] != -1) return dp[pos];
            ll res = 0;
            int up = limit_ ? min(limit, a[pos]) : limit;
            for (int i = 0; i <= up; i ++) {
                if (pos <= s.size() && i != s[pos - 1] - '0')
                    continue;
                res += self(self, pos - 1, limit_ && i == a[pos]);
            }
            return limit_ ? res : dp[pos] = res; 
        };

        auto cal = [&](ll x)
        {
            memset(dp, -1, sizeof dp);
            int len = 0;
            while (x) a[++ len] = x % 10, x /= 10;
            if (len < s.size())
                return 0ll;
            return dfs(dfs, len, 1);
        };

        return cal(finish) - cal(start - 1);
    }
};
