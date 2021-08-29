/*
数学方法：统计每个元素在所有奇数长度子数组出现的次数
方法是数左右元素的个数，能凑成奇数长度只有两种情况
- 左右都是奇数，加上自身
- 左右都是偶数，加上自身
*/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        int leftCount=0, rightCount=n-1;
        int res = 0;
        for(int i=0; i<n; i++){
            leftCount = i;  rightCount = n-i-1;
            int leftOdd = (leftCount+1)/2;
            int rightOdd = (rightCount+1)/2;
            int leftEven = leftCount/2+1;
            int rightEven = rightCount/2+1;
            res += arr[i] * (leftOdd*rightOdd + leftEven*rightEven);
        }
        return res;
    }
};

// 也可以以空间换时间，创建一个前缀和数组prefixSum，存放前i个元素的sum
// 这样一段长度的元素和为prefixSum[j]-prefixSum[i]+nums[j]

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixSum(n+1, 0);
        for(int i=1; i<=n; i++){
            prefixSum[i] = prefixSum[i-1] + arr[i-1];
        }
        //int start=0;
        int res = 0;
        for(int i = 1; i <= n; i += 2) {
            for(int j = 0; j < n - i + 1; j ++) {
                // 使用前缀和
                res += prefixSum[j + i] - prefixSum[j];
            }
        }
        return res;
    }
};
