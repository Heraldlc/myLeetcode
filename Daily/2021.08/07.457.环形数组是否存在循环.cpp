/*
两种思路

- 用快慢指针判断是否成环，当快指针追上满指针的时候即为有环，当然有边界判断和题目条件约束
- 拓扑排序判断成环，对于循环数组可以看成图的另类表示，思路独特
*/

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto next = [&](int cur) {
            return ((cur + nums[cur]) % n + n) % n; // 保证返回值在 [0,n) 中
        };

        for (int i = 0; i < n; i++) {
            if (!nums[i]) {
                continue;
            }
            int slow = i, fast = next(i);
            // 判断非零且方向相同
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(slow)) {
                        return true;
                    } else {
                        break;
                    }
                }
                slow = next(slow);
                fast = next(next(fast));
            }
            int add = i;
            while (nums[add] * nums[next(add)] > 0) {
                int tmp = add;
                add = next(add);
                nums[tmp] = 0;
            }
        }
        return false;
    }
};