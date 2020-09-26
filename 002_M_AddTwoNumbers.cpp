/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * @brief  : LC 3. Longest Substring Without Repeating Characters
 * @author : apadhi
 * 
 * Runtime: 36 ms, faster than 67.72% of C++ online submissions for Add Two Numbers.
 * Memory Usage: 71.1 MB, less than 27.57% of C++ online submissions for Add Two Numbers.

 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* l3 = NULL, *temp = NULL;
        ListNode* head = NULL;
        
        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            int value = l1->val + l2->val + carry;
            
            // cout << l1->val << " + " << l2->val << " = " << value << endl;
            
            temp = new ListNode(value % 10);
            
            if(l3 == NULL) {
                l3 = temp;
                head = l3;
            } else {
                l3->next = temp;
                l3 = temp;
            }
            
            l1 = l1->next;
            l2 = l2->next;
            
            carry = value / 10;
        }
        
        while(l1 != NULL) {
            int value = l1->val + carry;
            temp = new ListNode(value % 10);
            l3 -> next = temp;
            l3 = temp;
            l1 = l1->next;
            
            carry = value / 10;
        }
        
        while(l2 != NULL) {
            int value = l2->val + carry;
            temp = new ListNode(value % 10);
            
            l3->next = temp;
            l3 = temp;
            l2 = l2->next;
            
            carry = value / 10;
        }
        
        if(carry > 0) {
            temp = new ListNode(1);
            l3->next = temp;
            l3 = temp;
        }
        
        return head;
    }
};