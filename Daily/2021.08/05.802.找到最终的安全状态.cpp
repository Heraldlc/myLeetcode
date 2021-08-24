// 根据题意，如果该点在一个环内或者到达一个环，则认为这是不安全的
// 使用**拓扑排序**，将图逆序后，在逆序图中，开始时安全节点的入度肯定为0，
// 所以我们可以通过这个安全节点，找到下一个节点，将其入度减去1， 
// 那么对现有所有的安全节点作出这样的操作后，如果这个节点的入度为0，
// 也就认为在原图中这个节点的后继节点肯定都是安全节点，所以这个节点也必定是一个安全节点，
// 以上也就是拓扑排序的正确性所在。

// 因此整个过程就是将图进行反向，再跑一遍拓扑排序，如果某个节点出现在拓扑序列，说明其进入过队列，说明其入度为 0，其是安全的，其余节点则是在环内非安全节点。

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // 给定的二维数组表示了一个邻接矩阵
        // 图中节点个数
        // 1 维护一个入读为0的数组，一个所有节点入度的数组(反向后)
        // 2 将图反向做拓扑排序
        // 3 将起始入度为0的节点入队
        // 4 如果队列不空，弹出队首，对其他节点入度减1，将入度为0的节点入队
        // 5 遍历入度数组，入度为0的就是答案
        int length = graph.size();
		vector<vector<int>> dgraph(length);
		vector<int> inDegree(length);
		vector<int> res;
		//将图逆序
		for(unsigned i = 0; i < length; ++i) {
			for(auto x : graph[i]){
				dgraph[x].push_back(i);
			}
			inDegree[i] =  graph[i].size(); 
		}
		//将起始入度为0的节点存在队列中
		queue<int> q;
		for(unsigned i = 0; i < length; ++i) {
			if(inDegree[i] == 0){
				q.push(i);
			}
		}
		//拓扑排序
		while(!q.empty()){
			int cur = q.front(); //front返回第一个元素引用
			for(auto next : dgraph[cur]){
				inDegree[next]--;
				if(inDegree[next] == 0) {
					q.push(next);
					// res.push_back(next);
				}
			}
			q.pop(); //删除第一个元素，弹出
		}
		//遍历入度数组，入度为0就是答案之一
		for(int i =0; i < length; i++){
			if(inDegree[i] == 0)
				res.push_back(i);
		}
		return res;       

    }
};