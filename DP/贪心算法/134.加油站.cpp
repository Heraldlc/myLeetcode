// 图像解法
// 精髓是【保持累加和大于0】
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0, minSum = INT_MAX;
        int start = 0; // 先假定从0出发
        for(int i=0; i<n; i++){
            // 求和
            sum += gas[i] - cost[i];
            if(sum < minSum){
                // 油耗不是最小点了，要更换
                start = i+1;
                minSum = sum;
            }
        }
        if(sum < 0) return -1; // 不可能循环了
        return start == n? 0 : start;
    }
};


// 用贪心思路解决这道题的关键在于以下这个结论：
// 如果选择站点 i 作为起点「恰好」无法走到站点 j，那么 i 和 j 中间的任意站点 k 都不可能作为起点。
int canCompleteCircuit(int[] gas, int[] cost) {
    int n = gas.length;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += gas[i] - cost[i];
    }
    if (sum < 0) {
        // 总油量小于总的消耗，无解
        return -1;
    }
    // 记录油箱中的油量
    int tank = 0;
    // 记录起点
    int start = 0;
    for (int i = 0; i < n; i++) {
        tank += gas[i] - cost[i];
        if (tank < 0) {
            // 无法从 start 走到 i
            // 所以站点 i + 1 应该是起点
            tank = 0;
            start = i + 1;
        }
    }
    return start == n ? 0 : start;
}

// 其实没有区别