// 依旧是前序遍历+递归，因为给定的是一个vector，所以我们需要自己创造递归函数用于控制左右

class Solution {
public:
    TreeNode* doBuild(vector<int>& nums, int start, int end){
        if(start>end) return nullptr;

        //找max，并记录其坐标index
        int max = -1;
        int index = -1;
        for(int i = start; i<= end; i++)
        {
            if(nums[i] > max){
                max = nums[i];
                index = i;
            }
        }
        TreeNode *root = new TreeNode(max);

        root->left = doBuild(nums, start, index-1);
        root->right = doBuild(nums, index+1, end);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return doBuild(nums, 0, nums.size()-1);
    }
};