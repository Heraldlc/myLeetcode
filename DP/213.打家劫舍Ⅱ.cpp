/* 房子是环形，意味着头尾连在一块，也不能偷了
首尾不能偷，有三种情况
- 头，尾房子都不偷
- 头偷，尾不偷
- 头不偷，尾偷
比较后两种情况即可，因为第一种情况包含其中
*/

class Solution {
public:
    int robRange(vector<int>&nums, int start, int end){
        int n = nums.size();
        int dp_i_1 =0, dp_i_2=0;
        int dp_i=0;
        for(int i=end; i>=start; i--){
            dp_i = max(dp_i_1, dp_i_2+nums[i]);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        // 比较两种情况即可
        return max(robRange(nums, 0, n-2), robRange(nums, 1, n-1));
    }
};