/*
plus限定，很有意思
a cc ca cv 输出A的个数
根据定义的dp状态不同有两种解法
1 dp(n,a_num,copy) n表示操作数，a_num表示输出A的数量，copy表示缓冲区中A的个数
*/

class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=1; i<=n; i++)
        {
            dp[i] = dp[i-1]+1;
            for(int j=2; j<i; j++)
            {
                dp[i] = max(dp[i], dp[j-2]*(i-j+1));
            }
        }
        return dp[n];
    }
};