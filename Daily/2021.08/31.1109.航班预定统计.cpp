/*
见识到了差分

以下是官方题解思路讲解：
注意到一个预订记录实际上代表了一个区间的增量。我们的任务是将这些增量叠加得到答案。因此，我们可以使用差分解决本题。

差分数组对应的概念是前缀和数组，对于数组 [1,2,2,4][1,2,2,4]，其差分数组为 [1,1,0,2][1,1,0,2]，差分数组的第 ii 个数即为原数组的第 i-1i−1 个元素和第 ii 个元素的差值，也就是说我们对差分数组求前缀和即可得到原数组。

差分数组的性质是，当我们希望对原数组的某一个区间 [l,r][l,r] 施加一个增量\textit{inc}inc 时，差分数组 dd 对应的改变是：d[l]d[l] 增加 inc，d[r+1]d[r+1] 减少 inc。这样对于区间的修改就变为了对于两个位置的修改。并且这种修改是可以叠加的，即当我们多次对原数组的不同区间施加不同的增量，我们只要按规则修改差分数组即可。

在本题中，我们可以遍历给定的预定记录数组，每次 O(1)O(1) 地完成对差分数组的修改即可。当我们完成了差分数组的修改，只需要最后求出差分数组的前缀和即可得到目标数组。

注意本题中日期从 11 开始，因此我们需要相应的调整数组下标对应关系，对于预定记录 \textit{booking}=[l,r,\textit{inc}]booking=[l,r,inc]，我们需要让 d[l-1]d[l−1] 增加 \textit{inc}inc，d[r]d[r] 减少 \textit{inc}inc。特别地，当 rr 为 nn 时，我们无需修改 d[r]d[r]，因为这个位置溢出了下标范围。如果求前缀和时考虑该位置，那么该位置对应的前缀和值必定为 00。读者们可以自行思考原因，以加深对差分数组的理解。

*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 创建差分数组diff
        vector<int> diff(n);
        for(auto& booking : bookings){
            int start = booking[0];
            int end = booking[1];
            int inc = booking[2];
            // modify diff
            diff[start-1] += inc;
            if(end < n) diff[end] -= inc;
        }
        
        // 对diff求前缀和即可
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }
        return diff;
    }
};