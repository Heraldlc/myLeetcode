/*
动态规划
dp[i][j]表示s1[0~i-1]和s2[0~j-1]的最短编辑距离

- 其中若s1[i-1]和s2[j-1]不相等，dp更新应该是
min(
    dp[i-1][j] + 1,  # 删除
    dp[i][j-1] + 1,  # 插入
    dp[i-1][j-1] + 1  # 替换
    ) s
- 若相等，不用做任何操作dp[i][j] = dp[i-1][j-1]
- Attention! 因为我们的base case将0作为" "，比较的时候是i-1和j-1
*/

class Solution {
public:
    int minFunc(int a, int b, int c)
    {
        return min(a, min(b, c));
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length(); 
        if (n * m == 0) return n + m;       
        int dp[m+1][n+1];
        // base case
        dp[0][0] = 0;
        for(int i = 1; i<=m; i++) dp[i][0] = i; // Attention!
        for(int j = 1; j<=n; j++) dp[0][j] = j;

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(word1[i-1] == word2[j-1]) // Attention!
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = minFunc(
                        dp[i-1][j] +1,
                        dp[i][j-1] +1,
                        dp[i-1][j-1] +1
                    );
            }
        }
        return dp[m][n];
    }
};