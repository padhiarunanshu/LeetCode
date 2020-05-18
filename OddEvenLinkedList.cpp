/**
 * @brief LC : OddEven Singly linked list
 * @author : apadhi
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if((head == NULL) || (head != NULL && head->next == NULL)) {
            return head;
        }

        ListNode* oddP = head;
        ListNode* evenP = head->next;
        ListNode* temp1 = oddP, *temp2 = evenP;
        
        while (oddP->next != NULL && evenP->next != NULL) {
            oddP->next = evenP->next;
            oddP = oddP->next;
            evenP->next = oddP->next;
            evenP = evenP->next;
        }
        oddP->next = temp2;
        temp2 = NULL;
        return temp1; 
    }
};
