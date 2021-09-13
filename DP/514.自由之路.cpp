// 拨转盘找字符的最短操作次数
// 穷举+最值的动态规划：明确[状态]和[选择]

// 什么是[状态]? 变得值有ring[i]和key[j]，所以要定义dp函数为：
// dp(ring, i, key, j)表示ring[i]到key[j]的操作次数

// 如何[选择]? ring上无非是顺时针或者逆时针拨动，这样得到的状态转移逻辑是
// for(int k : key[j]在ring上的索引){
//     res= min(i顺时针拨动到k，i逆时针拨动到k)
// }

class Solution {
public:
    // 建立映射表
    unordered_map<char, vector<int>> charToIndex;
    // 备忘录
    vector<vector<int>> memo;
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        memo.resize(m, vector<int>(n, 0));
        // 映射表填值
        for(int i=0; i<m; i++){
            charToIndex[ring[i]].push_back(i);
        }
        return dp(ring, 0, key, 0);
    }

    int dp(string &ring, int i, string &key, int j){
        // base case
        if(j == key.size()){
            return 0;
        }
        // 越界
        if(i == ring.size() || j == key.size()) return INT_MAX;

        if(memo[i][j] != 0) return memo[i][j];
        int n = key.size();
        int res = INT_MAX;
        // 要找的是Key[j]在ring中的索引
        for(int k : charToIndex[key[j]]){
            int delta = abs(k-i);
            // 状态转移：转动有顺时针和逆时针，次数需要取较小值
            delta = min(delta, n-delta);
            // 是否可以这么转，指针已经拨到了ring[k]，去找key[j+1]
            int subProblem = dp(ring, k, key, j+1);
            res = min(res, delta + subProblem + 1);
        }
        memo[i][j] = res;
        return res;
    }
};