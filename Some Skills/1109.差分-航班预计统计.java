class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        /*题目翻译一下：给定一个长度为n的数组nums，所有元素都是0。
        然后输入一个bookings,里面若干三元组(i,j,k)
        要求对nums的闭区间[i-1, j-1]的所有元素加上k
        差分数组问题
        */
        int[] diff = new int[n];
        diff[0] = 0;
        
        for(int[] booking : bookings){
            int i = booking[0] - 1;
            int j = booking[1] - 1;
            int val = booking[2];
            // 对diff操作
            diff[i] += val;
            if(j + 1 < n){
                diff[j + 1] -= val;
            }
            
        }
        // 还原原数组
        for(int i=1; i<n; i++){
            diff[i] += diff[i-1];
        }
        return diff;
    }
}