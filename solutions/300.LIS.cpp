/*
经典动归
- 定义dp[i]表示以nums[i]结尾的LIS
- 那么数学归纳的逻辑就是取nums[i]比对之前的0->i-1
- 如果nums[i]>nums[j]，尝试把nums[i]加入dp[j]，取较大值
- 最后返回dp数组中的最大值即可
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i]表示以nums[i]结尾的LIS
        // 那么数学归纳的逻辑就是取nms[i]比对之前的0->i-1
        // 如果nums[i]>nums[j]，尝试把nums[i]加入dp[j]，取较大值
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        // 返回的是dp中的最大值
        int res = 0; 
        for(int m=0; m<n; m++)
        {
            if(res<dp[m])
                res = dp[m];
        }
        return res;
    }
};

/*
方法二：Patient Game
- 使用了二分搜索查找poker应该存放的位置
- 牌堆数就是LIS的长度
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 二分搜索解法 Patient game
        int n = nums.size();
        vector<int> top(n); // 已有牌堆顶元素
        int piles = 0; // 牌堆个数
        
        for(int i=0; i<n; i++)
        {
            // 需要处理的扑克数
            int poker = nums[i];
            // 开始二分搜索能放的位置
            int left =0, right = piles;
            while(left < right)
            {
                int mid = left+(right - left)/2;
                if(top[mid] > poker)  // 去左边搜
                    right = mid;
                else if(top[mid]<poker) // 去右边搜
                    left = mid+1;
                else if(top[mid]==poker)
                    right = mid;
            }
            // 没地方放了，自己开个新堆
            if(left == piles) piles++;
            top[left] = poker;
        }
        // 牌堆数就是LIS长度
        return piles;
    }
};