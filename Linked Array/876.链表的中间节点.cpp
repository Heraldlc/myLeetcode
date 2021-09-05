// 每当慢指针 slow 前进一步，快指针 fast 就前进两步，这样，当 fast 走到链表末尾时，slow 就指向了链表中点

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // 每当慢指针 slow 前进一步，快指针 fast 就前进两步
        ListNode *fast = head, *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};