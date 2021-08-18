/*
动规
状态有三个在变：天数n，A的个数，连续L的个数，因为不会记录3连L，所以可以看结尾处L的个数
dp(n, a_num, l)
0<= i <= n  n+1个
0<= a_num <= 1  2个
0<= l <= 2  3个

已知n-1的dp(n-1,?, ?)那么就要看n如何放置了
- 如果是'P',意味着A不会变，结尾也没有L了 +=dp(n-1, j, k:0->2) j表示n-1时a的个数，包含在第二层循环
- 如果是'A',则前面一定不能有A，否则不会记录，+= dp(n-1, 0, k:0->2)
- 如果是'L',则结尾不要有连续2个L即可， +=dp(n-1, j, k-1)

base case
dp(0,0,0) = 1,因为A的数量和L数量都是0，也可以获得奖励

*/

class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3)));  // 长度，A 的数量，结尾连续 L 的数量
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            // 以 P 结尾的数量
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 2; k++) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
                }
            }
            // 以 A 结尾的数量
            for (int k = 0; k <= 2; k++) {
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
            }
            // 以 L 结尾的数量
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= 2; k++) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                }
            }
        }
        int sum = 0;
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 2; k++) {
                sum = (sum + dp[n][j][k]) % MOD;
            }
        }
        return sum;
    }
};