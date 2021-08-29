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
            // 剪枝，桶装不下了
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

// 在桶的视角
//本题可以理解为将一组数，分到k个桶里，使得每个桶的容量都相等=target=sum/k，在此，以桶的视角去遍历这些数值，将不超过本桶容量的加入桶里，不符合的数值加到其他桶里，将已经加入桶内的数值赋为false，桶内的值也增加nums[i],如果退出选择的话就将其设置为true，桶的值也变回原值。

public:
    bool backtrack(vector<int>& nums, int k, int bucket, 
                    int start, int target, vector<bool>& used)
    {
        if(k==0){
            // 所有桶都转满了
            return true;
        }
        if(bucket == target){
            // 装满了当前桶，递归穷举下一个
            // 需要让桶从nums[0]开始选数字
            return backtrack(nums, k-1, 0, 0, target, used);
        } 
        // 从start开始向后探查有效的Nums[i]装入当前桶
        for(int i=start; i<nums.size(); i++){
            // 作剪枝
            if(used[i]){
                // nums[i]已经被用过了
                continue;
            }
            // 做选择
            bucket += nums[i];
            used[i] = true;
            if(backtrack(nums, k, bucket, i+1, target, used)) return true;
            // 撤销选择
            bucket -= nums[i];
            used[i] = false;
        }
        // 穷举所有的都不行
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {        
        if(k > nums.size()) return false;
        int sum = 0;
        for(int v : nums) sum += v;
        if(sum % k != 0) return false;
        vector<bool> used(nums.size());
        int target = sum/k;
        return backtrack(nums, k, 0, 0, target, used);
    }
    
};