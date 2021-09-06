class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // k =2 直接枚举所有情况
        // dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1]+prices[i])
        // dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0]-prices[i])
        // dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1]+prices[i])
        // dp[i][1][1] = max(dp[i-1][1][1], -prices[i])
        int dp_i_10 = 0, dp_i_11 = INT_MIN;
        int dp_i_20 = 0, dp_i_21 = INT_MIN;
        for(int price : prices){
            dp_i_20 = max(dp_i_20, dp_i_21 + price);
            dp_i_21 = max(dp_i_21, dp_i_10 - price);
            dp_i_10 = max(dp_i_10, dp_i_11 + price);
            dp_i_11 = max(dp_i_11, -price);
        }
        return dp_i_20;
    }
};