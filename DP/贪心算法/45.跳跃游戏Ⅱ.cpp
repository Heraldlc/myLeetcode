// 先看动态规划的暴力解法，用memo消除重复子问题
class Solution {
public:
    vector<int> memo; // 备忘录
    int jump(vector<int>& nums) {
        int n = nums.size();
        memo = vector<int>(n, n);
        return dp(nums, 0);
    }

    int dp(vector<int>& nums, int p){
        // base case
        int n = nums.size();
        if(p >= n-1)
            return 0;
        
        if(memo[p] != n)
            return memo[p];
        
        int step = nums[p];
        for(int i=1; i<=step; i++){
            // 穷举每一个子问题可能
            int subProblem = dp(nums, p+i);
            memo[p] = min(memo[p], subProblem+1);
        }
        return memo[p];
    }
};

// 贪心解法
class Solution {
public:
    int jump(vector<int>& nums) {
        // 每次都选择可以跳最远的，也就是值最大的
        int n = nums.size();
        int end = 0, farthest = 0;
        int jumps = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(nums[i] + i, farthest);
            if (end == i) {
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};