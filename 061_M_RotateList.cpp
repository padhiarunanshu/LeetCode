class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* p = head;
        int len = 1;
        while (p->next != nullptr) {
            p = p->next;
            len++;
        }
        p->next = head;
        k = k % len;
        for (int i = 0; i < len - k; i++) {
            p = p->next;
        }
        head = p->next;
        p->next = nullptr;
        
        return head;
    }
};