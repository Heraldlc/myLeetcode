class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // 快慢指针，快指针领先k步
        ListNode *low = head, *fast = head;
        for(int i=0; i<k; i++){
            fast = fast->next;
        }
        while(fast != NULL){
            low = low->next;
            fast = fast->next;
        }
        return low;
    }
};