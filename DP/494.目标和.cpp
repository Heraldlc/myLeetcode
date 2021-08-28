/*
本题揭示回溯和动规之间的关系，值得好好研究
*/

// 直接使用回溯模板，会【超时】
class Solution {
public:
    int res;
    void backtrack(vector<int> &nums, int i, int rest){
        if(i == nums.size()){
            if(rest == 0) // 说明恰好凑出
                res++;
            return;
        }
        // 给nums[i]进行"负"选择，因为是rest，所以是加
        rest += nums[i];
        // 穷举nums[i+1]
        backtrack(nums, i+1, rest);
        // 撤销选择
        rest -= nums[i];

        // ‘正’选择
        rest -= nums[i];
        backtrack(nums, i+1, rest);
        rest += nums[i];

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return 0;       
        backtrack(nums, 0, target);
        return res;
    }
};

// ------------------------------------------------------------------------
// 在python中可以使用元组配合哈希表dict来做备忘录，其他语言没有元组，可以用
// 把“状态”转为“字符串”的形式作为哈希表的键，这是一种常见的小技巧！
class Solution {
public:
    unordered_map<string, int> memo;
    int dp(vector<int> &nums, int i, int rest){
        if(i == nums.size()){
            if(rest == 0) return 1;
        return 0;
        }
        // 转成string才能作为key
        string key = to_string(i) + ',' + to_string(rest);
        if(memo.find(key) != memo.end())
            return memo[key];
        // 还是穷举
        int res = dp(nums, i+1, rest-nums[i]) + dp(nums, i+1, rest+nums[i]);
        // 写入备忘录
        memo[key] = res;
        return res;

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return dp(nums, 0, target);
    }
};

// -----------------------------------------------------------------------
// dp解法,转换成背包问题
class Solution {
public:
    // 计算nums有几个子集和为sum
    int subset(vector<int> &nums, int sum){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector(sum+1, 0));
        // base case
        for(int i=0; i<n+1; i++) dp[i][0] = 1;
        // 
        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(j >= nums[i-1]) dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else dp[i][j] = dp[i-1][j];
            }               
        }
        return dp[n][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int n : nums)
            sum += n;
        // 有两种情况不可能存在合法子集划分
        if(sum < target || (sum+target)%2==1) return 0;
        return subset(nums, (sum + target)/2);
    }
};