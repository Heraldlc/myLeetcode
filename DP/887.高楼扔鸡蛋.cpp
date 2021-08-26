//N层楼中扔鸡蛋，若要找到鸡蛋恰好不碎的楼层 f，
//在最坏情况下(穷尽搜索区间才找到解)所需的最少实验次数.
class Solution {
public:
    int superEggDrop(int K, int N)
    {
        memo.clear();
        return dp(K,N); 
    }

    int dp(int K, int N)
    {
        //检索备忘录，若备忘录中有相应的状态结果，直接返回
        if(memo.find( N * 100 + K ) != memo.end() ) return memo[N*100+K];
        //base case
        if(K == 1)
        {
            memo[N*100 + 1] = N;
            return N;
        } 
        if(N == 0)
        {
            memo[K] = 0;
            return 0;
        }
        int res = INT_MAX;
        //使用二分搜索 穷举 K, N 状态的所有扔鸡蛋的选择，
        //找到最坏情况下找到 f 的最少实验次数
        int low = 1,high = N;
        while(low <= high)
        {
            int mid = low +(high - low)/2;
            int broken = dp(K-1,mid-1);//在mid层扔鸡蛋，鸡蛋碎,测试楼层[1,mid-1]
            int not_broken = dp(K,N-mid);//在mid层人鸡蛋，鸡蛋不碎,测试楼层[mid+1,N]
            if(broken > not_broken)//打碎了是最坏情况
            {
                high = mid-1;//缩小搜索区间到[low,mid-1]
                res = min(res,broken + 1);
            }
            else   //没打碎是最坏情况
            {
                low = mid + 1;//缩小搜索区间 [mid+1,high]
                res = min(res,not_broken + 1);
            }
        }
        //计算的结果记录到备忘录中
        memo[N*100+K] = res;
        return res;
    }   
private:
    unordered_map<int,int> memo;//备忘录，记录计算过的状态
};

/* 解法二：
重新考虑dp的定义，dp(k, m) = n k表示鸡蛋数，n表示m次的扔可以测的楼层数
状态转移方程是dp[k][m] = dp[k][m-1] + dp[k-1][m-1] + 1;
- dp(k,m)显然就是总的层数
- dp(k, m-1)就是楼上的层数，因为鸡蛋没碎才可能去楼上，所以k不变，总扔次数-1
- dp(k-1, m-1)就是楼下的层数，因为鸡蛋碎了才会去楼下，k-1，总仍数-1
*/

class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp(k, m) = n k表示鸡蛋数，n表示m次的扔可以测的楼层数
        int dp[k+1][n+1];
        for(int i =0; i<=n; i++) dp[0][i] = 0;
        for(int j =0; j<=k; j++) dp[j][0] = 0;
        int m = 0;
        while(dp[k][m] < n)
        {
            m++;
            for(int i=1; i<=k; i++)
            {
                dp[i][m] = dp[i][m-1] + dp[i-1][m-1] + 1;
            }
        }
        return m;
    }
};