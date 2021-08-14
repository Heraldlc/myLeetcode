/*
七夕特供，理解题意模拟一遍即可

f[i][j]表示i->j的喜爱度，match数组方便查找pairs
肯定需要对0-(n-1)做一次遍历逐个比较,这就是x
- 找到与x配对的y，通过y = match[x]
- 找到x喜爱度列表中对y的喜爱度，返回给index
- 那么，在0-(index-1)的区域里都有可能出现u，遍历这个区间，找与u配对的v
- 若f[u][x]<f[u][v]，x便不开心

*/

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int unhappy = 0;
        // 预处理pre, f[i][j]表示i->j的喜爱度
        vector<vector<int>> f(n, vector<int>(n));
        for(int i=0; i<n; i++)
        {
            for(int j =0; j<n-1; j++)
            f[i][preferences[i][j]] = j;
        }

        // 预处理pairs，方便查找是否匹配
        vector<int> match(n);
        for(int i =0; i<n/2; i++)
        {
            match[pairs[i][0]] = pairs[i][1];
            match[pairs[i][1]] = pairs[i][0];
        }
        // 遍历0->n-1
        for(int i=0; i<n; i++)
        {
            // 找与x匹配的y,并查出x喜爱列表中对y的喜爱度index
            int index = f[i][match[i]];
            // 在0-index-1间都有可能是u
            for(int j=0; j<index; j++)
            {
                int u = preferences[i][j];
                int v = match[u];
                if(f[u][i] < f[u][v])
                {
                    unhappy++;
                    break;
                }
            }  
        }
        return unhappy;        
    }
};