class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 每一步都计算一下从当前位置最远能跳到哪里，然后和一个全局最优的最远剧里对比
        int n = nums.size();
        int farest = 0;
        for(int i=0; i<n-1; i++){
            // 不断计算能跳到最远是哪里
            farest = max(farest, i+nums[i]);
            // 可能碰到0，卡住不跳
            if(farest <= i) return false;
        }
        return farest >= n-1;
    }

};