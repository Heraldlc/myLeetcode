// 比较明显的回溯思路
// 定义backtrack()的时候，按照模拟过程一个一个确定参数即可
// k确定了决策树的高度，n确定了决策树宽度！

class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int start, int k, int n, vector<int> &track){
        // 长度达到了k就要返回了
        if(track.size() == k){
            res.push_back(track);
            return ;
        }
        
        for(int i=start; i<=n; i++){
            track.push_back(i);
            backtrack(i+1, k, n, track);
            track.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        // base case
        if(k <= 0 || n <=0) return res;
        vector<int> track;
        backtrack(1, k, n, track);
        return res;
    }
};