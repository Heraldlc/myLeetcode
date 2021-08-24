// 按照labuladong思路求解，动态规划dp[i][j]
// 归纳思想：假设我们已知某个状态，如何推导出dp[i][j]
// 二维数组的dp，需要总结遍历路线，本题采用了反向遍历
// 但有些不理解j的设置，需要反复

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // dp[i][j]表示s中i->j的最长回文子序列
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // base case
        for(int i=0; i<n; i++) 
            dp[i][i] = 1;
        // from down to up traverse
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++) // j=i+1 Attention!
            {
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] +2;
                else dp[i][j] = max(dp[i][j-1], dp[i+1][j]); // 子序列不用+1
            }
        }
        return dp[0][n-1];
    }
};


// 状态压缩的解法
// 采用一维数组存储dp

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // 状态压缩解法
        int n = s.size();
        vector<int> dp(n, 1);

        for(int i=n-2; i>=0; i--)
        {
            int pre =0;
            for(int j=i+1; j<n; j++)
            {
                int tmp = dp[j];
                if(s[i] == s[j]) dp[j] = pre +2;
                else dp[j] = max(dp[j], dp[j-1]);
                pre = tmp;
            }
        }
        return dp[n-1];
    }
};