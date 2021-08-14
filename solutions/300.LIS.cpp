/*
经典动归
- 定义dp[i]表示以nums[i]结尾的LIS
- 那么数学归纳的逻辑就是取nums[i]比对之前的0->i-1
- 如果nums[i]>nums[j]，尝试把nums[i]加入dp[j]，取较大值
- 最后返回dp数组中的最大值即可
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i]表示以nums[i]结尾的LIS
        // 那么数学归纳的逻辑就是取nms[i]比对之前的0->i-1
        // 如果nums[i]>nums[j]，尝试把nums[i]加入dp[j]，取较大值
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        // 返回的是dp中的最大值
        int res = 0; 
        for(int m=0; m<n; m++)
        {
            if(res<dp[m])
                res = dp[m];
        }
        return res;
    }
};