/*
方法一:
使用自顶向下的备忘录，避免重复递归
*/

class Solution {
public:
    vector<int> memo; // 存储dp()的值，作备忘录
    int rob(vector<int>& nums) {
        int n = nums.size();
        memo.insert(memo.begin(), n, -1);
        return dp(nums, 0);
    }

    int dp(vector<int> &nums, int start)
    {
        if(start >= nums.size()) return 0;
        // 避免重复递归
        if(memo[start] != -1) return memo[start];
        int res = max(
            // 不取，去下一个房子
            dp(nums, start+1),
            // 取这个房子
            nums[start] + dp(nums,start+2)
        );
        memo[start] = res;
        return res;
    }
};

/*
方法二：
使用自底向上的解法
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2, 0); // dp[x]表示从x房子开始拿到的钱
        // base case
        // dp[n-1] = 0;
        for(int i=n-1; i>= 0; i--){
            dp[i] = max(dp[i+1], nums[i]+dp[i+2]);
        }
        return dp[0];
    }
};

// 因为状态转移只和dp[i]最近的两个状态dp[i+1]和dp[i+2]有关，所以可以进一步压缩空间复杂度
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // 记录dp[i+1]和dp[i+2]
        int dp_i_1=0, dp_i_2=0;
        // 记录dp[i]
        int dp_i = 0;
        for(int i=n-1; i>=0; i--){
            dp_i = max(dp_i_1, nums[i]+dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};