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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = NULL;
        
        ListNode* p = head, *prev = NULL;
        
        while (p != NULL) {
            bool removed = false;
            while (p->next != NULL && p->val == p->next->val) {
                p = p->next;
                removed = true;
            }
            if (removed) {
                if (prev != NULL) {
                    prev->next = p->next;
                }
                p = p->next;
                
            } else {
                if (prev == NULL) newHead = p;
                prev = p;
                p = p->next;       
            }
        }
        if (prev != NULL) prev->next = NULL;
        
        return newHead;
    }
};
