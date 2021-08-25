/*
797.
DFS 回溯搜爆！
*/

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    //backtrack(搜索点，图)
    void backtrack(vector<vector<int>>& graph, int now, int n)
    {
        if(now == n){
            result.push_back(path);
            return;
        }

        // auto and reality version
        // for(auto &i : graph[now]){
        //     path.push_back(i);
        //     backtrack(graph, i, n);
        //     path.pop_back();
        // }
        for(int i=0; i<graph[now].size(); i++){
            path.push_back(graph[now][i]);
            backtrack(graph, graph[now][i], n);
            path.pop_back();
        }
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size(); // 节点的个数
        path.push_back(0);
        backtrack(graph, 0, n-1);
        return result;
    }
};
