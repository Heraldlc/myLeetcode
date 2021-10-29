class Solution {
public:
    vector<int> visited;

    bool isPowerOfTwo(int n) {
        return (n & (n - 1)) == 0;
    }

    bool backtrack(string nums, int index, int curNum) {
        if(index == nums.length()) {
            return isPowerOfTwo(curNum);
        }

        for(int i = index; i < nums.size(); i++) {
            // 剪枝
            if((curNum == 0 && nums[i] == 0) || visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])) {
                continue;
            }
            visited[i] = 1;
            int nxt = nums[i] - '0';
            if(backtrack(nums, index+1, curNum * 10 + nxt)) {
                return true;
            }
            visited[i] = 0;
        }
        return false;
    }

    bool reorderedPowerOf2(int n) {
        string nums = to_string(n);
        sort(nums.begin(), nums.end());
        visited.resize(nums.size());
        return backtrack(nums, 0, 0);
    }
   
};