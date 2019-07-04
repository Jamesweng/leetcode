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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode* p1 = head, *p2 = head;
        ListNode* right_head = NULL, *right_p1 = NULL;
        
        for (; p2 != NULL; ) {
            if (p2->val < x) {
                p1 = p2;
                p2 = p2->next;
            } else {
                if (right_p1 == NULL) {
                    right_head = right_p1 = p2;
                } else {
                    right_p1->next = p2;
                    right_p1 = p2;
                }
                
                p2 = p2->next;
                if (p1->next == p2) {
                    if (p1 == head) {
                        head = p2;
                    }
                    p1 = p2;
                } else {
                    p1->next = p2;
                }
                right_p1->next = NULL;
            }
        }
        
        if (p1 != NULL) {
            p1->next = right_head;
            return head;
        } else {
            return right_head;
        }
    }
};
