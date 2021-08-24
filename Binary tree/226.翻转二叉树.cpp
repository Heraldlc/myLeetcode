// 交换左右节点，递归即可，二叉树的后序遍历

// 难点:
// 如何把二叉树的问题细化成每个节点要做的事情

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //递归，reverse(开始节点，左，右)
        //前序遍历
        if(root == nullptr) return 0;
        //*****前序遍历部分******
        //交换左右
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;  

        //前序遍历todo
        invertTree(root->left);
        invertTree(root->right);

        return root;
        
    }
};