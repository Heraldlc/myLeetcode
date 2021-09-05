class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 快慢指针，领先n步即可
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *fast = head, *low = dummy;
        for(int i=0; i<n; i++) fast = fast->next;
        while(fast){
            fast = fast->next;
            low = low->next;
        }
        low->next = low->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
