/*
可以将问题转化为0-1背包问题，先对数组求和sum，然后看能否恰好分成sum/2
即：
给一个可以装载sum/2的背包，和n个物体，物体重量Nums[i]，现在装物体，能否【恰好】装满
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum+=num;
        if(sum%2 != 0) return false;
        int n = nums.size();
        sum = sum/2;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        // base case
        for(int i=0; i<=n; i++)
            dp[i][0] = true;
        // transform
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(j - nums[i-1] <0){
                    // 背包容量不足
                    dp[i][j] = dp[i-1][j];
                }else
                {
                    // 装入或不装入，看是否存在一种情况能够恰好装满
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
};

// 状态压缩后，改为一维数组

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum+=num;
        if(sum%2 != 0) return false;
        int n = nums.size();
        sum = sum/2;
        vector<bool> dp(sum+1, false);
        dp[0] = true; // 背包空间为0，就是恰好装满

        for(int i=0; i<n; i++){
            for(int j=sum; j>=0; j--){
                if(j-nums[i] >= 0) 
                    dp[j] = dp[j] || dp[j-nums[i]];
            }
        }

        return dp[sum];
    }
};