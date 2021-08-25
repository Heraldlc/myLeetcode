// 787.k站中转内最便宜的航班

// BFS搜索模板，其中关于auto和pair<>的应用值得细细琢磨

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, int> vi;
        vi[src] = 0;

        unordered_map<int, vector<pair<int, int>>> fdic; // 类似邻接表
        for (auto& f : flights) {
            fdic[f[0]].emplace_back(f[1], f[2]); // 建图的数据
        }

        queue<pair<int, int>> que;
        que.push({src, 0});
        while (k-- >= 0) {
            for (int len = (int)que.size(); len > 0; len--) {
                auto [pos, price] = que.front();
                que.pop();

                for (auto [d, p] : fdic[pos]) {
                    if (vi.find(d) != vi.end() && vi[d] <= price + p) continue;
                    vi[d] = price + p;
                    que.push({d, price + p});
                }
            }
        }

        return vi.find(dst) == vi.end() ? -1 : vi[dst];
    }
};

