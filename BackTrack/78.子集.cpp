/*
数学归纳法：
subset([1,2,3]) - subset([1,2]) = [3],[1,3],[2,3],[1,2,3]

而这个结果，就是把 sebset([1,2]) 的结果中每个集合再添加上 3。
换句话说，如果 A = subset([1,2]) ，那么：
subset([1,2,3]) = A + [A[i].add(3) for i = 1..len(A)]

这就是一个典型的递归结构嘛，[1,2,3] 的子集可以由 [1,2] 追加得出，[1,2] 的子集可以由 [1] 追加得出
base case 显然就是当输入集合为空集时，输出子集也就是一个空集。
*/
class Solution {
public:    
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return {{}};
        int n = nums.back();        
        nums.pop_back(); // 删除最后一个元素
        // 递归求子集
        vector<vector<int>> res = subsets(nums);

        // 添加原来Nums内最后的，也就是多出来的n
        int size = res.size();
        for(int i=0; i<size; i++){
            res.push_back(res[i]); // 不影响原本的,在末尾加一个副本方便后续操作
            res.back().push_back(n); // 加上n
        }
        return res;
    }
};

// 也可以用回溯模板进行求解
class Solution {
public:
    vector<vector<int>> res;
    
    void backtrack(vector<int> &nums, int start, vector<int> &track)
    {
        //if(start == nums.size()) return track;
        res.push_back(track);
        for(int i=start; i<nums.size(); i++){
            track.push_back(nums[i]);
            backtrack(nums, i+1, track);
            track.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track; // 记录走过的路径
        backtrack(nums, 0, track);
        return res;
    }
};