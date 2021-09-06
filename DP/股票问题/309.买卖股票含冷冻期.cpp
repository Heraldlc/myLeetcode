class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        // dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        int dp_pre_0 = 0; // 代表dp[i-2][0]
        for(int i=0; i<n; i++){
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
            dp_pre_0 = temp;
        }
        return dp_i_0;
    }
};