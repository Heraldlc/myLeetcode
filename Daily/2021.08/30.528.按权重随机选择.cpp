/*
既然选择概率为wei[i]/sum，我们以sum和划分所有数，即按照1-sum内取随机数

- upper_bound()函数，用于在指定范围内查找大于目标值的第一个元素
具体来说

求出前缀和表。paritial_sum()就是求前缀和，w[0] = W[0], w[1] = W[0] + W[1]...如此推算
求出前缀和表后最后一位数所包含的就是所有数字的和。用以上的例子 w.back() 最终会包含 1 + 2 + 3 + 4 = 10
求出一个随机数，rand() % w.back(); 假设 w.back() = 10, 那么这里产生的数字是 0-9。如果我们继续用以上的例子的话那么其每个数字所对应取到的index便为：
0 ：代表取到 index 0
1，2: 代表取到 index 1
3，4，5: 代表取到 index 2
6，7, 8, 9: 代表取到 index 3
用以上的例子产生的前缀和表 [1, 3, 6, 10], 可以发现我们用得到的数字调用 upper_bound() 会刚好使其指向我们的 index 位置。
0 的 upper_bound 会指向 index 0, 因为第一个比 0 大的数是 w[0] = 1;
1, 2 的 upper_bound 会指向 index 1, 因为第一个比 1 或者 2 大的数是 w[1] = 3;
3，4，5 的 upper_bound 会指向 index 2, 因为第一个比 {3, 4, 5} 大的数是 w[2] = 6;
6，7, 8, 9 的 upper_bound 会指向 index 3, 因为第一个比 {6，7, 8, 9} 大的数是 w[3] = 10;

*/

class Solution {
    vector<int> w;
public:
    Solution(vector<int>& W) {
        partial_sum(W.begin(), W.end(), back_inserter(w));
        //等同于 w.push_back(W[0]); for(int i = 1; i < W.size(); ++i) w.push_back(w.back() + W[i]);
    }
    
    int pickIndex() {
        int weight = rand() % w.back();
        return upper_bound(w.begin(), w.end(), weight) - w.begin();
    }
};
