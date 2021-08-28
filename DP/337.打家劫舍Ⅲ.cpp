/*
现在房子排列为树形，也是一个选择的问题
*/

class Solution {
public:
    unordered_map<TreeNode*, int> memo;  // memo(选择的节点，偷盗的金额)
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        // memo消除子问题
        if(memo.find(root) != memo.end()) return memo[root];
        // 取钱，去下下家做选择
        int do_it = root->val
                + (root->left == nullptr? 0: rob(root->left->left) + rob(root->left->right))
                + (root->right == nullptr? 0: rob(root->right->left) + rob(root->right->right));
        // 不取，那就去下家
        int not_do = rob(root->left) + rob(root->right);
        // 选择收益更大的
        int res = max(do_it, not_do);
        memo[root] = res;
        return res;

    }
};