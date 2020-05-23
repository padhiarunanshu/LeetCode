/**
 * @brief  : LC 83. Remove Duplicates from Sorted List
 * @author : apadhi
 */
 
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode* first = head;
        ListNode* second = NULL;

        if(head->next != NULL) second = head->next;
        
        while(second != NULL) {
            if(first->val == second->val) {
                ListNode* temp = second;
                second = second->next;
                first->next = second;
                
                delete temp;
            } else {
                first = first->next;
                second = second->next;
            }
        }
        return head;
    }
};
