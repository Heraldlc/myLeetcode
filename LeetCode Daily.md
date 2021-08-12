# LeetCode Daily

## 1. [两数之和](https://leetcode-cn.com/problems/two-sum/)

暴力方法：双指针遍历，一个一个比对是否等于target，时间复杂度O（n^2)

为了效率，可以使用unordered_map，无序map<key, value>，因为要输出位置，所以**value放在nums中位置，key放nums[i]的值**

- 遍历数组，首先要往map中存值，便要判断map中是否存在nums[i]，

**unordered_map API**

```c++
//find 查找key所在的元素，如果key存在，返回对应迭代器；如果不存在，返回end
iterator find ( const key_type& k );
//count 统计key在map中出现的次数，实际上unordered_map不允许有重复key
size_type count ( const key_type& key ) const；
```

代码

方法一

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i=0; i<nums.size(); i++)
            {
            //not found the second one
                if(m.find(nums[i]) == m.end()  )
                {
                    //store the first one position 
                    m[target - nums[i]] = i;
                }else
                {
                    //found the second one
                    res.push_back(m[nums[i]]);
                    res.push_back(i);
                    break;
                }
            }
            return res;
        } 
};
```

方法二

简单粗暴，map记录已经遍历过的数字和对应的索引。当遍历一个新数字的时候去map里查询target-nums[i]，如果出现了，说明一组配对就出现了，直接返回结果即可

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            if (m.count(t)) return { m[t], i };
            m[nums[i]] = i;
        }
        return {};
    }
};
```



## 1736. [替换隐藏数字得到的最晚时间](https://leetcode-cn.com/problems/latest-time-by-replacing-hidden-digits/)

按照四种情况判断即可，注意格式是hh:mm，:也占了一位，所以表示时间的是`time[0],time[1], time[3], time[4]`

- time[4]没有要求，最大为9
- time[3]没有要求，最大为5
- time[1]需要判断：如果是time[0]是2，则只能最大为3，因为一天最大23时；如果time[0]是0或1，最大为9；
- time[0]需要看time[1]，time[1]如果小于等于3，则time[0]最大为2，否则就要最大为1

代码

```c++
class Solution {
public:
    string maximumTime(string time) {
        //四个判断，格式为hh:mm
        if (time[4] == '?') time[4] = '9';
        if (time[3] == '?') time[3] = '5';
        if (time[1] == '?'){
            if ( time[0] == '0' || time[0] == '1')
            time[1] = '9';
            else
            time[1] = '3';
        }
        if (time[0] == '?'){
            if(time[1]=='0'||time[1]=='1'||time[1]=='2'||time[1]=='3') time[0]='2';
            else time[0]='1';
        }
        return time;
    }
};
```



## 4. [寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

给定数组正序，省了很多麻烦，先从暴力方法思考，最简单的便是将两个数组合并merge，然后从合并的数组里选出中位数。

我们假设有两个`pointer *i, *j`，分别指向`A, B`两个数组，i=0，j=0，分别比较A[i]和B[j]

1. 如果`A[i]<=B[j]`，则把`A[i]`放入新的数组，`i++`

2. 如果`A[i] > B[j]`, 则把`B[j]` 放入新的数组中，j 往后移一位，即 `j+1`.

3. 重复步骤#1 和 #2，直到`i`移到`A`最后，或者`j`移到`B`最后。

4. 如果`j`移动到`B`数组最后，那么直接把剩下的所有`A`依次放入新的数组中.

5. 如果`i`移动到`A`数组最后，那么直接把剩下的所有`B`依次放入新的数组中.

这道题可以转化成寻找两个有序数组中的**第** *k* 小的数，其中 *k* 为 (m+n)/2 或 (m+n)/2+1

代码

```c++
class Solution {
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */

        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;

        while (true) {
            // 边界情况
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};
```

官方题解：分割线的艺术

默认A数组是个数较小的数组，二分查找的关键是交叉小于



## 1743. [从相邻元素对还原数组](https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs/)

**没有理解，还需要复习！**

代码

```c++
//自定义链表节点
typedef struct List {
    int data;
    List *left;
    List *right;
} List;

//建立链表节点
List *create(int data) {
    List *n = new List();
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
        unordered_map<int, List *> map;
        List *f, *s;
        unordered_map<int, List *>::iterator it;
        //建立链表和元素的映射关系，并拼接还原链表
        for (vector<int> v:adjacentPairs) {
            //为新加入的节点建立映射
            it = map.find(v[0]);
            if (it == map.end())
                map[v[0]] = f = create(v[0]);
            else {
                f = it->second;
                //如果某节点连接后2个相邻元素都已经确定，将其从映射中移除，保证循环结束后map中只有链表两端元素
                map.erase(v[0]);
            }
            //同上
            it = map.find(v[1]);
            if (it == map.end())
                map[v[1]] = s = create(v[1]);
            else {
                s = it->second;
                map.erase(v[1]);
            }
            //将v[0]和v[1]两节点连接
            if (f->left == nullptr)
                f->left = s;
            else
                f->right = s;
            if (s->left == nullptr)
                s->left = f;
            else
                s->right = f;
        }
        //获得链表的一个端点
        List *head = map.begin()->second;
        vector<int> ans;
        //依次输出链表
        while (true) {
            ans.push_back(head->data);
            //已经输出的链表置为INT32_MAX，用于标记
            head->data = INT32_MAX;
            if (head->left != nullptr && head->left->data != INT32_MAX)
                head = head->left;
            else if (head->right != nullptr && head->right->data != INT32_MAX)
                head = head->right;
            else
                break;
        }
        return ans;
    }
};
```



## 671. [二叉树中第二小的节点](https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/)

思路

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

代码

```c++
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
```

亮点：unsigned的强制转换判断大小用法

值得注意的是，因为题目说明了node->val > 0, 所以如果没有找到返回-1，将-1转化为unsigned，C++中，unsigned(-1) = INT_MAX，这样直接返回`return min(unsigned(leftMinVal), unsigned(rightMinVal));`即可，学到了强制转换unsigned的一种用法！



## 863. [二叉树中所有距离为 K 的结点](https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/)

思路

如果我们可以从target出发，只需要使用深度优先搜索BFS，输出距离为K的节点即可，但是题目没有给定父节点，因此需要找到root-target的路径，同样**可以使用BFS查找，同时使用哈希表记录节点的父节点**

因为每个节点都是唯一的，哈希表的键key用节点的值表示，哈希表的值为父亲节点，定义为`unordered_map<int, TreeNode*> parents`

代码

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
```



## 226. [翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)

思路

交换左右节点，递归即可，二叉树的后序遍历

代码

```c++
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
```

难点

如何把二叉树的问题细化成每个节点要做的事情



## 1104. [二叉树寻路](https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/)

思路

如果是正常完美二叉树，label除以2便是父节点，但是有"之"字形，所有偶数层有对称情况，但对称层数满足一个数学情况：

定义完美二叉树层数为`h`，则该二叉树共有`2^h-1`节点，第`h`层有`2^(h-1)`个节点

```c++
//label和它在该层的对称点sym_label满足
//label + sym_label = 该层第一点(2^(h-1)-1+1) + 该层最后一点(2^h-1)
```

数学题

代码

```c++
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
```



## 171. [Excel表列序号](https://leetcode-cn.com/problems/excel-sheet-column-number/)

26进制

A-Z的映射可以借助ASCII值，`字母的值=columnTitle[i] - 'A' +1`

代码

```c++
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int res = 0;
        int mul = 0;
        for(int i= n-1; i>=0; i--)
        {
            int num = columnTitle[i] - 'A' + 1;
            res += num * pow(26, mul);
            mul++;
        }
        return res;
    }
};
```



## 116. [填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)

前序遍历 递归，注意不同父节点的左右节点如何相连？使用单节点输入的递归函数签名无法做到，那就自己写一个函数，输入双节点进行操作

代码

```c++
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
```



## 114. [二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)

后序遍历的递归，注意进行转换的过程

代码

```c++
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
```



## 654. [最大二叉树](https://leetcode-cn.com/problems/maximum-binary-tree/)

依旧是前序遍历+递归，因为给定的是一个vector，所以我们需要自己创造递归函数用于控制左右

代码

```c++
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
```



## 611. [有效三角形的个数](https://leetcode-cn.com/problems/valid-triangle-number/)

思路

在a<=b<=c的时候，a+b>c即可，为了提升效率，可以在确定nums[a]+nums[b]>nums[k]时，在[b+1,n-1]内二分查找k，k-b即为输出

代码

```c++
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int left = j + 1, right = n - 1, k = j;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (nums[mid] < nums[i] + nums[j]) {
                        k = mid;
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                res += k - j;
            }
        }
        return res;
    }
};
```

## 802. [找到最终的安全状态](https://leetcode-cn.com/problems/find-eventual-safe-states/)

思路

根据题意，如果该点在一个环内或者到达一个环，则认为这是不安全的，使用**拓扑排序**，将图逆序后，在逆序图中，开始时安全节点的入度肯定为0， 所以我们可以通过这个安全节点，找到下一个节点，将其入度减去1， 那么对现有所有的安全节点作出这样的操作后，如果这个节点的入度为0，也就认为在原图中这个节点的后继节点肯定都是安全节点，所以这个节点也必定是一个安全节点，以上也就是拓扑排序的正确性所在。

因此整个过程就是将图进行反向，再跑一遍拓扑排序，如果某个节点出现在拓扑序列，说明其进入过队列，说明其入度为 0，其是安全的，其余节点则是在环内非安全节点。

代码

```c++
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
   		int length = graph.size();
		vector<vector<int>> dgraph(length);
		vector<int> inDegree(length);
		vector<int> res;
		//将图逆序
		for(unsigned i = 0; i < length; ++i) {
			for(auto x : graph[i]){
				dgraph[x].push_back(i);
			}
			inDegree[i] =  graph[i].size(); 
		}
		//将起始入度为0的节点存在队列中
		queue<int> q;
		for(unsigned i = 0; i < length; ++i) {
			if(inDegree[i] == 0){
				q.push(i);
			}
		}
		//拓扑排序
		while(!q.empty()){
			int cur = q.front(); //front返回第一个元素引用
			for(auto next : dgraph[cur]){
				inDegree[next]--;
				if(inDegree[next] == 0) {
					q.push(next);
					// res.push_back(next);
				}
			}
			q.pop(); //删除第一个元素，弹出
		}
		//遍历入度数组，入度为0就是答案之一
		for(int i =0; i < length; i++){
			if(inDegree[i] == 0)
				res.push_back(i);
		}
		return res;
    }
```

总结

- 熟悉拓扑排序的写法，就是一个队列，入队，入度减一，入读为0者出队
- 在正向拓扑不一定适合的时候尝试将图反向，用反向图拓扑



## 847. [访问所有节点的最短路径](https://leetcode-cn.com/problems/shortest-path-visiting-all-nodes/)

hard题

三元组<u, mask, dist>  广度优先搜索BFS，用队列

细节：用哈希表<u, mask>检测是否被搜索过

```c++
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> seen(n, vector<int>(1 << n));
        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i, 0);
            seen[i][1 << i] = true;
        }

        int ans = 0;
        while (!q.empty()) {
            auto [u, mask, dist] = q.front();
            q.pop();
            if (mask == (1 << n) - 1) {
                ans = dist;
                break;
            }
            // 搜索相邻的节点
            for (int v: graph[u]) {
                // 将 mask 的第 v 位置为 1
                int mask_v = mask | (1 << v);
                if (!seen[v][mask_v]) {
                    q.emplace(v, mask_v, dist + 1);
                    seen[v][mask_v] = true;
                }
            }
        }
        return ans;
    }
};
```

- **状态压缩**：用一个变量表示状态，常见方式利用一个n位k进制数mask表示当前n个节点所处的k个不同状态
- 本题是基于状态压缩的BFS算法



## 457. [环形数组是否存在循环](https://leetcode-cn.com/problems/circular-array-loop/)

两种思路

- 用快慢指针判断是否成环，当快指针追上满指针的时候即为有环，当然有边界判断和题目条件约束
- 拓扑排序判断成环，对于循环数组可以看成图的另类表示，思路独特

```c++
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto next = [&](int cur) {
            return ((cur + nums[cur]) % n + n) % n; // 保证返回值在 [0,n) 中
        };

        for (int i = 0; i < n; i++) {
            if (!nums[i]) {
                continue;
            }
            int slow = i, fast = next(i);
            // 判断非零且方向相同
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(slow)) {
                        return true;
                    } else {
                        break;
                    }
                }
                slow = next(slow);
                fast = next(next(fast));
            }
            int add = i;
            while (nums[add] * nums[next(add)] > 0) {
                int tmp = add;
                add = next(add);
                nums[tmp] = 0;
            }
        }
        return false;
    }
};
```



## 1137. [第 N 个泰波那契数](https://leetcode-cn.com/problems/n-th-tribonacci-number/)

斐波拉契数组，常规动态规划，使用带**备忘录**的方法进行剪枝

```c++
class Solution {
public:
    int dp(vector<int> &memo, int n)
    {
        if(n == 0) return 0;
        if(n == 1 || n ==2 ) return 1;
        if(memo[n] != 0) return memo[n];
        memo[n] = dp(memo, n-1) + dp(memo, n-2) + dp(memo, n-3);
        return memo[n];
    }
        
    int tribonacci(int n) {
        // dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
        if(n <1) return 0;
        vector<int> memo(n+1, 0);
        return dp(memo, n);
    }
};
```



## 313. [超级丑数](https://leetcode-cn.com/problems/super-ugly-number/)

题目要求的超级丑数，是质因数都在给定数组内，那么从**1**开始，所有的丑数都是由数组中的丑数相乘得到的，为了从小到大输出，我们可以建立一个小根堆heap，每次取出堆顶元素x，则对于数组primes的任意质数p，p*x也是超级丑数，此时再把加入小根堆，再取出堆顶元素即可

**要点：**

- 用priority_queue<long, vector<long>, greator<long>>实现的小根堆，从小往大排序；大根堆为less，
- unordered_set的使用是为了避免存入相同的数

```c++
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int sz = primes.size();        
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> heap;
        seen.insert(1);
        heap.push(1);
        int ugly = 0;
        for(int i=0; i<n; i++)
        {
            long cur = heap.top();
            heap.pop();
            ugly = (int)cur;
            for(int j=0; j<sz; j++)
            {
                long next = primes[j] * cur;
                if( seen.insert(next).second ) 
                    heap.push(next);
            }

        }
        return ugly;
    }
};
```



