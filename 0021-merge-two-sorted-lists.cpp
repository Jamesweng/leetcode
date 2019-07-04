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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = NULL;
        ListNode* q = NULL;
        
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL) {
                if (l2 != NULL && l2->val < l1->val) {
                    if (p == NULL) {
                        p = l2;
                        q = p;
                    } else {
                        p->next = l2;
                        p = p->next;
                    }
                    l2 = l2->next;
                } else {
                    if (p == NULL) {
                        p = l1;
                        q = p;
                    } else {
                        p->next = l1;
                        p = p->next;
                    }
                    l1 = l1->next;
                }
            } else {
                if (p == NULL) {
                    p = l2;
                    q = p;
                } else {
                    p->next = l2;
                    p = p->next;
                }
                l2 = l2->next;
            }
        }
        
        return q;
    }
};
