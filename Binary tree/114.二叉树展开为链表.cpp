// 后序遍历的递归，注意进行转换的过程

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return ;//若不判断边界会报错
        //后序遍历
        flatten(root->left);
        flatten(root->right);
        //实际动作
        //1. 临时存储左右节点
        TreeNode *m_left = root->left;
        TreeNode *m_right = root->right;
        //2. 左置空，右置左
        root->left = nullptr;
        root->right = m_left;
        //3. 原来的右应该接到原左的最右下角
        TreeNode *p = root;
        while(p->right != nullptr)
        {
            p = p->right;
        }
        p->right = m_right;
    }
};