/*
首先明确一下起点 start 和终点 target 是什么，怎么判断到达了终点？

显然起点就是 root 根节点，终点就是最靠近根节点的那个「叶子节点」嘛，叶子节点就是两个子节点都是 null 的节点：
if (cur.left == null && cur.right == null) 
    // 到达叶子节点

剩下的按照模板写出即可，注意depth一开始为1
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        // BFS
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        int depth = 1;
        q.emplace(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                TreeNode *cur = q.front();
                //是否到达重点
                q.pop();
                if(cur->left ==nullptr && cur->right == nullptr) return depth;
                //相邻入队
                if(cur->left != nullptr)  q.emplace(cur->left);
                if(cur->right != nullptr) q.emplace(cur->right);
            }
            depth++;            
        }
        return depth;
    }
};