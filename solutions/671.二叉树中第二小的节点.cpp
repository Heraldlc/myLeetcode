/*
看起来不难，因为题目所给树的特殊性，父节点一定是左右子节点中val较小的那一个，用代码来说就是

```c++
root->val = min(root->left->val, root->right->val)
```

那么我们要找**第二小**的数，第一想到的是只需要输出root节点中较大的那一个，便是第二小的值，但案例`[1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1]`

![image-20210727204610428](C:\Users\penglab\AppData\Roaming\Typora\typora-user-images\image-20210727204610428.png)

告诉我们只看root是不够的，其左右子节点不能代表第二小的数，所以得用**递归**去找：

- 若`left->val == root->val`，意味着此时左节点上的就是最小值，不符合题意
- 而根据提议，`left->val`只能大于`root->val`，所以需要去左节点继续寻找
- 右节点同理
- 递归的边界条件就是寻找的root点为空或者是其左右节点为空
*/

/*
亮点：unsigned的强制转换判断大小用法
值得注意的是，因为题目说明了node->val > 0, 所以如果没有找到返回-1，将-1转化为unsigned
C++中，unsigned(-1) = INT_MAX，这样直接返回return min(unsigned(leftMinVal), unsigned(rightMinVal))即可，
学到了强制转换unsigned的一种用法！
*/

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        //边界条件判断
        // if(root == nullptr) return -1;
        // if(root->left == nullptr) return -1;
        // if(root->left->val == root->right->val) return -1;
        //只需要输出root节点中较大的那一个，便是第二小的值(错误)
        //根节点左右节点的值并不能代表就是第二小的值，所以还是得递归
        if(root && root->left && root->right)
        {
            int leftMin =(root->val==root->left->val) ? findSecondMinimumValue(root->left) : root->left->val;
            int rightMin =(root->val==root->right->val)? findSecondMinimumValue(root->right):root->right->val;
            return min((unsigned)leftMin, (unsigned)rightMin);
        }
        return -1;
    }
};