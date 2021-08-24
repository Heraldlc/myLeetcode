/*
LCS 经典二维动归问题

# 定义dp[i][j]的含义
dp[i][j]表示s1[0~i-1]和s2[0~j-1]的LCS长度

# base case
将dp[0][..]和dp[..][0]看成空串""，这样就要赋值为0，那么下表应到n，而不是n-1
dp[0][..] = 0 || dp[..][0] = 0
因为空串不可能和任何串有公共子序列

# 如何推导，即状态转移方程
对于s1[i]和s2[j]
- 若s1[i] == s2[j] 把这个相同字符加入LCS即可dp[i][j] = dp[i-1][j-1]+1
- 若不相同，那就看哪个长dp[i][j] = max(dp[i][j-1], dp[i-1][j])
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // LCS
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        if(m == 0 || n == 0) return 0;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
};