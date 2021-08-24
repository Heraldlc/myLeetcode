// 我们首先考虑至少有两个元素的等差子序列，下文将其称作弱等差子序列。

// 由于尾项和公差可以确定一个等差数列，因此我们定义状态 f[i][d]f[i][d] 表示尾项为 \textit{nums}[i]nums[i]，公差为 dd 的弱等差子序列的个数。

// 我们用一个二重循环去遍历 \textit{nums}nums 中的所有元素对 (\textit{nums}[i],\textit{nums}[j])(nums[i],nums[j])，其中 j<ij<i。将 \textit{nums}[i]nums[i] 和 \textit{nums}[j]nums[j] 分别当作等差数列的尾项和倒数第二项，则该等差数列的公差 d=\textit{nums}[i]-\textit{nums}[j]d=nums[i]−nums[j]。由于公差相同，我们可以将 \textit{nums}[i]nums[i] 加到以 \textit{nums}[j]nums[j] 为尾项，公差为 dd 的弱等差子序列的末尾，这对应着状态转移 f[i][d] += f[j][d]f[i][d]+=f[j][d]。同时，(\textit{nums}[i],\textit{nums}[j])(nums[i],nums[j]) 这一对元素也可以当作一个弱等差子序列，故有状态转移

// f[i][d] += f[j][d] + 1
// f[i][d]+=f[j][d]+1

// 由于题目要统计的等差子序列至少有三个元素，我们回顾上述二重循环，其中「将 \textit{nums}[i]nums[i] 加到以 \textit{nums}[j]nums[j] 为尾项，公差为 dd 的弱等差子序列的末尾」这一操作，实际上就构成了一个至少有三个元素的等差子序列，因此我们将循环中的 f[j][d]f[j][d] 累加，即为答案。

// 代码实现时，由于 \textit{nums}[i]nums[i] 的范围很大，所以计算出的公差的范围也很大，我们可以将状态转移数组 ff 的第二维用哈希表代替。


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // dp[i][d]表示以nums[i]结尾，公差为d的状态转移方程
        int n = nums.size();
        int res = 0;
        vector<unordered_map<long long , int>> dp(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                long long diff = 1LL * nums[i] - nums[j];
                auto it = dp[j].find(diff);
                int cnt = it==dp[j].end() ? 0 : it->second;
                res += cnt;
                dp[i][diff] += cnt +1;
            }
        }
        return res; 
    }
};
