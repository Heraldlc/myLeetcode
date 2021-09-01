/*
贪心解法，按照区间右半部end升序排序，贪心的选择最早结束的
注意返回是需要移除的，代码中统计的是可以选择的
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 按end做升序排序
        int n = intervals.size();
        if( n == 0 ) return 0;
        sort(intervals.begin(), intervals.end(), [](auto &u, auto& v){
            return u[1]<v[1];
        });

        int res = 1;
        int end = intervals[0][1];
        // 以最小的end排除相交区间
        for(int i=1; i<n; i++){
            int start = intervals[i][0];
            if(start >= end){
                // 这是不相交区间，可以选择
                res++;
                end = intervals[i][1]; //更新x区间
            } 
        }
        return n-res; // 返回结果是需要移除的
    }
};