class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (ListNode * x : lists)
        {
            while (x)
            {
                minHeap.push(x->val);
                x = x->next;
            }
        }

        ListNode * dummy = new ListNode(-1);
        ListNode * x = dummy;
        while (!minHeap.empty())
        {
            int y = minHeap.top();    minHeap.pop();
            x->next = new ListNode(y);
            x = x->next;
        }
        return dummy->next;
    }
};
