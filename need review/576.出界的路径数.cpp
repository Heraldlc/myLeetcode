/*
动态规划，dp[i][j][k]表示走了k步到达坐标(i,j)时的路径数量

实际实现没有理解，需要复习
*/

class Solution {
public:
    int recursion(int remember[][52][52], int steps, int x, int y, int m, int n){
        if(x>n||x<=0||y>m||y<=0)
            return 1;
        else if(!steps)
            return 0;
        if(remember[x-1][y][steps-1]==-1)
            remember[x-1][y][steps-1]=recursion(remember, steps-1, x-1, y, m, n);
        if(remember[x+1][y][steps-1]==-1)
            remember[x+1][y][steps-1]=recursion(remember, steps-1, x+1, y, m, n);
        if(remember[x][y-1][steps-1]==-1)
            remember[x][y-1][steps-1]=recursion(remember, steps-1, x, y-1, m, n);
        if(remember[x][y+1][steps-1]==-1)
            remember[x][y+1][steps-1]=recursion(remember, steps-1, x, y+1, m, n);
        return ((long)remember[x-1][y][steps-1]+remember[x+1][y][steps-1]+remember[x][y-1][steps-1]+remember[x][y+1][steps-1])%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int remember[52][52][52];
        memset(remember, -1, sizeof(remember));//将remember数组初始化为-1
        return recursion(remember, maxMove, startColumn+1, startRow+1, m, n);
    }
};