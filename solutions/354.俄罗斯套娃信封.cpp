/*
当然legthOfLIS也可以用dp方式进行调用，这里只是为了AC的时候排名高一些
本题非常经典，需要复习

- 其中sort()发放的排序lambda表达式用法并不是那么清楚，可以的话请教一下
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

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        /* 
        先对w进行排序，升序；然后在h上找LIS
        若w相同，对其高度h进行降序排序，这是为了避免出现w相同的情况
        */
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](vector<int>&a, vector<int>&b){
            if(a[0] == b[0]) return a[1]>b[1];
            else return a[0]<b[0];
        });
        // 在h上找LIS，使用dp,搜索区域envelopes[i][0->n]
        // 创立高度数组方便计算
        vector<int> height(n);
        for(int i=0; i<n; i++) height[i] = envelopes[i][1];
        return lengthOfLIS(height);
    }
};