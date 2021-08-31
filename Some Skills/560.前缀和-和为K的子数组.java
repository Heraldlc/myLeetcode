/*
前缀和技巧：
前缀和数组 preSum 的含义也很好理解，preSum[i] 就是 nums[0..i-1] 的和。那么如果我们想求 nums[i..j] 的和，只需要一步操作 preSum[j+1]-preSum[i] 即可，而不需要重新去遍历数组了。

前缀和不难，却很有用，主要用于【处理数组区间的问题】。

比如说，让你统计班上同学考试成绩在不同分数段的百分比，也可以利用前缀和技巧：
*/

// C++会超时的解法
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 预处理，创建前缀和
        int n = nums.size();
        vector<int> preSum(n+1, 0);
        for(int i=1; i<=n; i++){
            preSum[i] = preSum[i-1] + nums[i-1];
        }
        int res = 0;
        // 找nums[i...j]=k
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(preSum[i] - preSum[j] == k){
                    res++;
                }
            }
        }
        return res;
    }
};

// java就不会
class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int[] sum = new int[n+1];
        sum[0] = 0;
        // 构造前缀和数组
        for(int i=1; i<=n; i++){
            sum[i] = sum[i-1] + nums[i-1];
        }
        // 找k
        int res = 0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(sum[i] - sum[j] == k){
                    res++;
                }
            }
        }
        return res;
    }
}

// 优化：
// 优化的思路是：我直接记录下有几个 sum[j] 和 sum[i] - k 相等，直接更新结果，就避免了内层的 for 循环。我们可以用哈希表，在记录前缀和的同时记录该前缀和出现的次数。
class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        // hashmap<前缀和，前缀和出现的次数>
        HashMap<Integer, Integer> preSum = new HashMap<>();
        // base case
        preSum.put(0, 1);

        int sum0_i = 0, ans = 0;
        for(int i=0; i<n; i++){
            sum0_i += nums[i];
            // 这是我们想找的值
            int sum0_j = sum0_i - k;
            if(preSum.containsKey(sum0_j)){
                ans += preSum.get(sum0_j);
            }
            preSum.put(sum0_i, preSum.getOrDefault(sum0_i, 0)+1);

        }
        return ans;
    }
}