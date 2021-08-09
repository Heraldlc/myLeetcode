// 暴力方法：双指针遍历，一个一个比对是否等于target，时间复杂度O（n^2)

// 为了效率，可以使用unordered_map，无序map<key, value>，因为要输出位置，所以**value放在nums中位置，key放nums[i]的值**

// - 遍历数组，首先要往map中存值，便要判断map中是否存在nums[i]


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i=0; i<nums.size(); i++)
            {
            //not found the second one
                if(m.find(nums[i]) == m.end()  )
                {
                    //store the first one position 
                    m[target - nums[i]] = i;
                }else
                {
                    //found the second one
                    res.push_back(m[nums[i]]);
                    res.push_back(i);
                    break;
                }
            }
            return res;
        } 
};