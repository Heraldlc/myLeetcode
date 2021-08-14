/*
- dp[i]表示以nums[i]为结尾的最大连续子数组和
- nums[i]有两个选择：
    - 与前面dp[i-1]连成一个子数组
    - 自成一派，要求nums[i]>dp[i-1]
- 那么便推导出状态转移方程：dp[i] = max(nums[i], dp[i-1]+nums[i])
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> dp(n);
        dp[0] = nums[0]; // base case
        for(int i=1; i<n; i++)  // 注意这里的i应从第二个元素开始，因为0已经给了base case
        {
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
        }

        int res = INT_MIN;
        for(int j=0; j<n; j++)
        {
            res = max(res, dp[j]);
        }
        return res;
    }
};