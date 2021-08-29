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