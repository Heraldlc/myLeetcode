// 很简单的遍历出结果

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();        
        if(n == 1) return nums;
        vector<int> res;
        int sum = nums[0];
        res.push_back(sum);
        for(int i=1; i<n; i++){
            sum += nums[i];
            res.push_back(sum);
        }
        return res;
    }
};