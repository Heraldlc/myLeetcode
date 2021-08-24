/*
前序遍历 递归
注意不同父节点的左右节点如何相连？
使用单节点输入的递归函数签名无法做到，那就自己写一个函数，输入双节点进行操作
*/

class Solution {
public:
    void connectLeftRight(Node* node1, Node* node2){
        if(node1 == NULL || node2== NULL) return ;
        //将传入的两个节点连接
        node1->next = node2;

        connectLeftRight(node1->left, node1->right);
        connectLeftRight(node2->left, node2->right);
        /*连接不是同一个父节点的左右节点*/
        connectLeftRight(node1->right, node2->left);
    }

    Node* connect(Node* root) {
        //前序遍历，递归
        if(root == NULL) return NULL;
        connectLeftRight(root->left, root->right);
        return root;
    }
};