// 863.二叉树中所有距离为k的结点

// 如果我们可以从target出发，只需要使用深度优先搜索BFS，输出距离为K的节点即可
// 但是题目没有给定父节点，因此需要找到root-target的路径，
// 同样**可以使用BFS查找，同时使用哈希表记录节点的父节点**

// 因为每个节点都是唯一的，哈希表的键key用节点的值表示，哈希表的值为父亲节点，
// 定义为`unordered_map<int, TreeNode*> parents`


class Solution {
public:
    //首先要找到root-target的路径，或者说是统计出节点的父节点，用哈希表存储
    unordered_map<int, TreeNode*> parents;
    vector<int> ans;

    //找父亲递归函数
    void findFather(TreeNode* node){
        if(node->left != NULL){
            parents[node->left->val] = node;
            findFather(node->left);
        }
        if(node->right != NULL){
            parents[node->right->val] = node;
            findFather(node->right);
        }
    }
    //找结果  起始点，从哪里来，步数，目标k
    void findAns(TreeNode* node, TreeNode* from, int step, int k){
        if(node == NULL) return;
        if(step == k) //找到了 
        {
            ans.push_back(node->val);
            return;
        }
        if(node->left != from) //向下寻找
        {
            findAns(node->left, node, step+1, k);
        }
        if(node->right != from)
        {
            findAns(node->right, node, step+1, k);
        }
        //向上寻找
        if(parents[node->val] != from)
        {
            findAns(parents[node->val], node, step+1, k);
        }
    }
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findFather(root);
        findAns(target,NULL,0,k);
        return ans;
    }
};