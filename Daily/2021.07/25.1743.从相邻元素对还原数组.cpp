1743.从相邻元素对还原数组 Medium

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