/*
题目描述：给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等
*/

// KEY: 关键是要知道怎么「做选择」，这样才能利用递归函数进行穷举。

// 基本边界情况：
// k大于nums的长度，自然是不能的
// nums所有元素的和不能被K整除，也是不能的

// 根据回溯模板写出，但会超时
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // 边界条件
        if(k > nums.size()) return false;
        int sum=0;
        for(int v:nums) sum+=v;
        if(sum % k != 0) return false;

        // 用k个桶来装数字
        vector<int> bucket(k);
        int target = sum/k; // 每个桶能装的数
        return backtrack(nums, bucket, 0, target);        
    }

    bool backtrack(vector<int>& nums, vector<int> &bucket, int index, int target){
        // 满足结束条件
        if(index == nums.size()){
            // 检查每个桶内数字和是否为target
            for(int i=0; i<bucket.size(); i++){
                if(bucket[i] != target) return false;
            }
            return true; // 成功
        }
        // 穷举，遍历所有桶
        for(int i=0; i<bucket.size(); i++){
            // 剪枝，桶装满了
            if(bucket[i]+nums[index] > target) continue;
            // 选择，将nums[i]装入
            bucket[i] += nums[index];
            if(backtrack(nums, bucket, index+1, target)) return true;
            // 撤销选择
            bucket[i] -= nums[index];
        }
        
        return false;
    }
    
};