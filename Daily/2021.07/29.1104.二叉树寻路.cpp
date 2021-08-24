// 1104.二叉树寻路

// 如果是正常完美二叉树，label除以2便是父节点，但是有"之"字形，所有偶数层有对称情况，但对称层数满足一个数学情况：

// 定义完美二叉树层数为`h`，则该二叉树共有`2^h-1`节点，第`h`层有`2^(h-1)`个节点

// ```c++
// label和它在该层的对称点sym_label满足
// label + sym_label = 该层第一点(2^(h-1)-1+1) + 该层最后一点(2^h-1)
// ```

// 数学题

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        vector<int> res;
        int h = log2(label) ; //log(label)+1 -1,父节点所在层     
        while (label >= 1)
        {
            ans.push_back(label);
            //管它奇偶都求对称，负负得正
            label /= 2;
            label = (pow(2, h) -1) + pow(2, h-1) - label; //注意次方不能用2^h
            h--;   
        }
        //但这样的输出是倒的
        for(int i = ans.size()-1; i>=0; i--)
            res.push_back(ans[i]);
        return res;
    }
};