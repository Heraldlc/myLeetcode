class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
         int n = nums.size();

        vector<int> mx(n + 1, INT_MIN);
        vector<int> mn(n + 1, INT_MAX);
        for(int i = 1; i <= n; i++) mx[i] = max(nums[i - 1], mx[i - 1]);
        for(int i = n - 1; i >= 0; i--) mn[i] = min(nums[i], mn[i + 1]);

        int l = -1, r = -1;

        for(int i = n - 1; i >= 0; i--) {
            // mn[i]: [i, n - 1] 的最小值
            // mx[i]: [0, i - 1] 的最大值
            if(mn[i] < mx[i]) {
                r = i;
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(mx[i] > mn[i]) {
                l = i - 1;
                break;
            }
        }

        if(l == -1) return 0;
        return r - l + 1;


    }
};