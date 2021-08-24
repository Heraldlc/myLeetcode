/*
hard题

三元组<u, mask, dist>  广度优先搜索BFS，用队列

细节：用哈希表<u, mask>检测是否被搜索过

- **状态压缩**：用一个变量表示状态，常见方式利用一个n位k进制数mask表示当前n个节点所处的k个不同状态
- 本题是基于状态压缩的BFS算法
*/


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
                int n = graph.size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> seen(n, vector<int>(1 << n));
        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i, 0);
            seen[i][1 << i] = true;
        }

        int ans = 0;
        while (!q.empty()) {
            auto [u, mask, dist] = q.front();
            q.pop();
            if (mask == (1 << n) - 1) {
                ans = dist;
                break;
            }
            // 搜索相邻的节点
            for (int v: graph[u]) {
                // 将 mask 的第 v 位置为 1
                int mask_v = mask | (1 << v);
                if (!seen[v][mask_v]) {
                    q.emplace(v, mask_v, dist + 1);
                    seen[v][mask_v] = true;
                }
            }
        }
        return ans;
 
    }
};