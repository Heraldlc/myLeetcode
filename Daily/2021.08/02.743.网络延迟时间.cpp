class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //--------------------- 朴素dijkstra算法 -----------------------//
        int INF = 1e9;
        vector<vector<int>> edge(n, vector<int>(n, INF));
        for (auto v : times)
        {
            int x = v[0],  y = v[1],  cost = v[2];
            x --;           //归一化，从0开始计
            y --;
            edge[x][y] = cost;
        }

        int start = k - 1;
        vector<int> dist(n, INF);
        vector<bool> visited(n, false);
        dist[start] = 0;
        for (int _ = 0; _ < n - 1; _ ++)
        {
            //---- 找未visit且距离起点最近的点
            int min_dist = INF;
            int x = -1;
            for (int i = 0; i < n; i ++)
            {
                if (visited[i] == false && dist[i] < min_dist)
                {
                    min_dist = dist[i];
                    x = i;
                }
            }
            if (x == -1)
                break;
            //---- 标记为visited
            visited[x] = true;
            //---- 更新x的邻居们
            for (int y = 0; y < n; y ++)
            {
                if (edge[x][y] < INF)
                {
                    if (dist[x] + edge[x][y] < dist[y])
                        dist[y] = dist[x] + edge[x][y];
                }
            }
        }

        //---- 最后一个到达的，是求max
        int res = *max_element(dist.begin(), dist.end());  
        return (res != INF ? res : -1);

    }

        
};