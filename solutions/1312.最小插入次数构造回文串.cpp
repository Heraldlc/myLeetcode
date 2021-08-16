/*
动态规划
同样dp[i][j]表示s[i~j]构造成回文串需要插入的次数
那么base case就是i==j时，本身便不需要插入了，dp(i,i)=0

如果s[i]==s[j],那么也不需要新的插入dp[i][j] = dp[i+1][j-1]
如果s[i]!=s[j],比较麻烦
- 我们需要先做选择，先将s[i~j-1]或者s[i+1~j]变成回文串，取代价较小的
- 然后一定需要一次插入，插入s[i]或者s[j]
dp[i][j] = min(dp[i][j-1], dp[i+1][j]) +1;
*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n-2; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = min(dp[i][j-1], dp[i+1][j]) +1;
            }
        }
        return dp[0][n-1];
    }
};

// 同样的状态压缩解法
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<int> dp(n, 0);

        for(int i = n-2; i>=0; i--)
        {
            int pre = 0;
            for(int j=i+1; j<n; j++)
            {
                int tmp = dp[j];
                if(s[i] == s[j])
                    dp[j] = pre;
                else
                    dp[j] = min(dp[j], dp[j-1])+1;
                pre = tmp;
            }
        }
        return dp[n-1];
    }
};