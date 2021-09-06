class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];
        for(int i=0; i<n; i++){
            if(i-1 == -1){
                dp[i][0] = 0;
                // 解释：
                //   dp[i][0] 
                // = max(dp[-1][0], dp[-1][1] + prices[i])
                // = max(0, -infinity + prices[i]) = 0
                dp[i][1] = -prices[i];
                //解释：
                //   dp[i][1] 
                // = max(dp[-1][1], dp[-1][0] - prices[i])
                // = max(-infinity, 0 - prices[i]) 
                // = -prices[i]
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }
        return dp[n-1][0];
    }
};

// 状态转移只和相邻的有关，可以使用O(1)的空间复杂度
// k == 1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //int dp[n][2];
        // base case
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for(int i=0; i<n; i++){
            dp_i_0 = max(dp_i_0, dp_i_1+prices[i]);
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;
    }
};