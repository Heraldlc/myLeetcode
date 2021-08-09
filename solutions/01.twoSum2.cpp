//简单粗暴，map记录已经遍历过的数字和对应的索引。
//当遍历一个新数字的时候去map里查询target-nums[i]，如果出现了，说明一组配对就出现了，直接返回结果即可

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            if (m.count(t)) return { m[t], i };
            m[nums[i]] = i;
        }
        return {};
    }
};