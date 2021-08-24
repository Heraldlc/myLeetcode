/*
n个数满足条件：
- 第 i 位的数字能被 i 整除
- i 能被第 i 位上的数字整除
且构成的数组有n个数，才可以被称作优美的排列

回溯问题
- 结束条件为 数组长度达到n+1（因为是从1开始），即找到n个符合要求的序列
- 选择条件 没有访问过，i%index==0, index%i==0

剩下的按照回溯问题模板写即可
for 选择 in 选择列表
    #做选择
    将该选择从选择列表排除
    路径.add(此选择)
    backtrack(路径，选择列表)
    #撤销选择
    路径.remove(此选择)
    将选择恢复到选择列表

*/

class Solution {
public:
    vector<vector<int>> match;
    vector<bool> visited;
    int cnt;

    void backtrack(int index, int n)
    {
        if(index == n+1)
        {
            cnt++;
            return;
        }
        for(auto &x : match[index])
        {
            if(!visited[x])
            {
                visited[x] = true;
                backtrack(index+1, n);
                visited[x] = false;
            }
        }
    }

    int countArrangement(int n) {
        match.resize(n+1);
        visited.resize(n+1);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i%j==0 || j%i ==0) match[i].push_back(j);
            }
        }
        backtrack(1, n);
        
        return cnt;
    }
};