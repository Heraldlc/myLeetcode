// 模拟题，模拟一遍题意即可
// 最大值只会在奇数位

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> nums(n+1);
        nums[0] = 0; nums[1] = 1;
        int res = 1;
        for(int i=1; i<n/2+1; i++){
            if(2*i <= n) nums[2*i] = nums[i];
            if(2*i+1 <= n){
                nums[2*i+1] = nums[i]+nums[i+1];
                res = max(res, nums[2*i+1]);
            }             
        }
        return res;
    }
};