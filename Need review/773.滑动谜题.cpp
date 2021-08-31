class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = ""; // 映射成一维
        string target = "123450";
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                start.push_back(board[i][j] + '0');
            }
        }
        
        // 记录的是索引
        vector<vector<int>> neighbor = {
            {1, 3},
            {0, 4, 2},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        }; 

        // BFS
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                string cur = q.front();
                q.pop();
                if(cur == target){
                    return step;
                }

                // 找到数字的索引
                int index = 0;
                for(; cur[index] != '0'; index++);
                // 将数组0和相邻数字交换
                for(int adj : neighbor[index]){
                    string new_board = cur;
                    swap(new_board[adj], new_board[index]);
                    // 防止回头路
                    if(!visited.count(new_board)){
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};