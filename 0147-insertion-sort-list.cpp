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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;
        
        ListNode* newHead = head;
        ListNode* p1, *p2, *p1Prev, *p2Prev;
        
        for (p1 = head->next, p1Prev = head; p1; ) {
            p1Prev->next = p1->next;
            p1->next = NULL;
            
            bool inserted = false;
            for (p2 = newHead, p2Prev = NULL; p2; ) {
                if (p1->val <= p2->val) {
                    if (p2Prev) {
                        p2Prev->next = p1;
                    } else {
                        newHead = p1;
                    }
                    
                    p1->next = p2;
                    inserted = true;
                    break;
                } else {
                    p2Prev = p2;
                    p2 = p2->next;
                }
            }
            if (!inserted) {
                p2Prev->next = p1;
            }
            
            if (p1Prev->next == p1) {
                p1Prev = p1;
                p1 = p1->next;
            } else {
                p1 = p1Prev->next;
            }
        }
        
        return newHead;
    }
};
