class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        /*按照起点排序，必须找到一个起点为0的，然后选择最长结尾的，确定为Pick
        然后在所有起点小于pick终点的区间里找，找长度最长的
        以此类推，直到能覆盖time
        */
        if(time == 0) return -1;
        int n = clips.size();
        // 按起点升序排序，若起点相同，降序排序
        sort(clips.begin(), clips.end(), [](auto& u, auto& v){
            if(u[0] == v[0])  return u[1] > v[1];
            return u[0]<v[0];
        });
        int res = 0;

        int curEnd = 0, nextEnd = 0;
        int i = 0;
        while(i<n && clips[i][0] <= curEnd){
            // 在第res个区间里贪心地选择
            while(i<n && clips[i][0] <= curEnd){
                nextEnd = max(nextEnd, clips[i][1]);
                i++;
            }
            // 找到了
            res++;
            curEnd = nextEnd;
            if(curEnd >= time) return res;
        }
        return -1;
    }
};