//还是和435.无重叠区间一样的贪心问题，只是这次区间边界要求更加严格，不能>=,得>

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 按end的大小进行升序
        int n = points.size();
        sort(points.begin(), points.end(), [](auto& u, auto& v){
            return u[1] < v[1];
        });

        int arrow = 1;
        int end = points[0][1];
        for(auto &point : points){
            int start = point[0];
            if(start > end){
                arrow++;
                end = point[1];
            }
        }
        return arrow;
    }
};