// 斐波拉契数组，常规动态规划，使用带**备忘录**的方法进行剪枝

class Solution {
public:
    int dp(vector<int> &memo, int n)
    {
        if(n == 0) return 0;
        if(n == 1 || n ==2 ) return 1;
        if(memo[n] != 0) return memo[n];
        memo[n] = dp(memo, n-1) + dp(memo, n-2) + dp(memo, n-3);
        return memo[n];
    }
        
    int tribonacci(int n) {
        // dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
        if(n <1) return 0;
        vector<int> memo(n+1, 0);
        return dp(memo, n);
    }
};