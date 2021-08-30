/*
在做回溯的时候写出决策树，对于参数设计很有帮助
全排列问题需要的是对所有元素的排列，i需要从0~len(nums)
组合的问题是k长度，穷举过程是递进的，所有需要安排一个start确定进程
子集问题和组合问题类似，也需要安排进程, 所以i从start开始
*/

class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int> &track){
        if(track.size() == nums.size()){
            res.push_back(track);
            return ;
        } 

        for(int i=0; i<nums.size(); i++){
            // 排除重复
            if(std::find(track.begin(), track.end(), nums[i]) != track.end()) continue;
            // 做选择
            track.push_back(nums[i]);
            backtrack(nums, track);
            track.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {{}};
        vector<int> track;
        backtrack(nums, track);
        return res;
    }
};