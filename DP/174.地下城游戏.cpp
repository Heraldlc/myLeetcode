// dp(i,j)表示的是(i,j)到达终点需要的生命值
// 状态推导时计算的为 min(dp(i,j+1), dp(i+1, j)) - grid[i][j]，需要保证此值>=0

class Solution {
public:
    vector<vector<int>> memo;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return dp(dungeon, 0, 0);
    }

    int dp(vector<vector<int>>& dungeon, int i, int j){
        int m = dungeon.size();
        int n = dungeon[0].size();
        if(i == m-1 && j == n-1){
            return dungeon[i][j] >= 0? 1 : -dungeon[i][j]+1;
        }

        if(i == m || j == n){
            // 越界了
            return INT_MAX;
        }

        // 避免重复计算
        if(memo[i][j] != -1) return memo[i][j];

        int res = min(dp(i,j+1), dp(i+1, j)) - dungeon[i][j];
        memo[i][j] = res >0 ? res : 1;
        return memo[i][j];
    }
};