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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p1 = head;
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode* p2 = head->next;
        ListNode* newhead = p2;
        
        while (p2 != NULL) {
            if (p2->next == NULL) {
                p2->next = p1;
                p1->next = NULL;
                break;
            }
            ListNode* p3 = p2->next;
            ListNode* p4 = p3->next;
            
            p2->next = p1;
            if (p4 != NULL) {
                p1->next = p4;
            } else {
                p1->next = p3;
            }
            
            p1 = p3;
            p2 = p4;
        }
        
        return newhead;
    }
};
