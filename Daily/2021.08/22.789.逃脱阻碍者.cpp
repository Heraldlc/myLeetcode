// 转换思维
// 逃脱者和阻碍者都以最短路径朝着目的地移动，如果阻碍者可以先到，只需要在目的地等待，逃脱者便永远无法逃脱
// 所以问题简化为计算玩家和目的地的曼哈顿距离以及每个阻碍者和目的地的曼哈顿距离
// 其中有个证明
// 阻碍者是否可以在玩家前往目的地途中拦截，答案否定，证明如下：
// 假设目的地是 TT，初始时玩家位于 SS，阻碍者位于 GG，阻碍者在 XX 点拦截玩家。

// 由于阻碍者和目的地的曼哈顿距离大于玩家和目的地的曼哈顿距离，因此 \text{dist}(G, T) > \text{dist}(S, T)dist(G,T)>dist(S,T)。

// 由于玩家会按照最短路径向目的地移动，因此如果阻碍者在 XX 点拦截玩家，则 XX 点一定在玩家前往目的地的最短路径上，满足 \text{dist}(S, X) + \text{dist}(X, T) = \text{dist}(S, T)dist(S,X)+dist(X,T)=dist(S,T)。

// 由于 XX 点是拦截点，因此阻碍者到达 XX 点的时间早于或等于玩家到达 XX 点的时间，即 \text{dist}(G, X) \le \text{dist}(S, X)dist(G,X)≤dist(S,X)。

// 因此有：

// \begin{aligned} \text{dist}(G, X) &\le \text{dist}(S, X) \\ \text{dist}(G, X) + \text{dist}(X, T) &\le \text{dist}(S, X) + \text{dist}(X, T) \\ \text{dist}(G, X) + \text{dist}(X, T) &\le \text{dist}(S, T) \end{aligned}
// dist(G,X)
// dist(G,X)+dist(X,T)
// dist(G,X)+dist(X,T)
// ​
  
// ≤dist(S,X)
// ≤dist(S,X)+dist(X,T)
// ≤dist(S,T)
// ​
 

// 由于阻碍者到目的地的最短路径长度是 \text{dist}(G, T)dist(G,T)，因此有

// \text{dist}(G, T) \le \text{dist}(G, X) + \text{dist}(X, T) \le \text{dist}(S, T)
// dist(G,T)≤dist(G,X)+dist(X,T)≤dist(S,T)

// 和条件 \text{dist}(G, T) > \text{dist}(S, T)dist(G,T)>dist(S,T) 矛盾。

// 因此当 \text{dist}(G, T) > \text{dist}(S, T)dist(G,T)>dist(S,T) 时，阻碍者不可能在玩家前往目的地的中途拦截，玩家可以成功逃脱。


class Solution {
public:    
    int distCount(vector<int> &point1, vector<int> &point2)
    {
        return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
    }
    
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int row = ghosts.size(); // 行数表示有多少个鬼
        // (0,0)到target的距离
        vector<int> origin(2, 0);
        int dist = distCount(origin, target);
        for(int i=0; i<row; i++)
        {
            if(distCount(ghosts[i], target) <= dist) return false;
        }
        return true;
        
    }
};