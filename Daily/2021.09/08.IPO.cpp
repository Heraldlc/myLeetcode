// 我们首先思考，如果不限制次数下我们可以获取的最大利润，我们应该如何处理？我们只需将所有的项目按照资本的大小进行排序，依次购入项目 ii，同时手中持有的资本增加 \textit{profits}[i]profits[i]，直到手中的持有的资本无法启动当前的项目为止。

// 如果初始资本 w \ge \max(\textit{capital})w≥max(capital)，我们直接返回利润中的 kk 个最大元素的和即可。

// 当前的题目中限定了可以选择的次数最多为 kk 次，这就意味着我们应该贪心地保证选择每次投资的项目获取的利润最大，这样就能保持选择 kk 次后获取的利润最大。

// 我们首先将项目按照所需资本的从小到大进行排序，每次进行选择时，假设当前手中持有的资本为 ww，我们应该从所有投入资本小于等于 ww 的项目中选择利润最大的项目 jj，然后此时我们更新手中持有的资本为 w + \textit{profits}[j]w+profits[j]，同时再从所有花费资本小于等于 w + \textit{profits}[j]w+profits[j] 的项目中选择，我们按照上述规则不断选择 kk 次即可。

// 我们利用大根堆的特性，我们将所有能够投资的项目的利润全部压入到堆中，每次从堆中取出最大值，然后更新手中持有的资本，同时将待选的项目利润进入堆，不断重复上述操作。

// 如果当前的堆为空，则此时我们应当直接返回。


class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(); // 有n个项目
        int curr = 0;
        priority_queue<int, vector<int>, less<int>> pq; // 大根堆
        vector<pair<int,int>> arr;

        for(int i=0; i<n; i++){
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<k; i++){
            while(curr < n && arr[curr].first <= w){
                pq.push(arr[curr].second);
                curr++;
            }
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
            else break;
        }
        return w;
    }    
};
