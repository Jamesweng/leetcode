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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        
        ListNode* p1 = head, *p2 = head;
        while (p1 != NULL && p2 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2) p2 = p2->next;
            else break;
            if (p1 == p2) break;
        }
        
        if (p1 == NULL || p2 == NULL) return NULL;
        
        ListNode* p3 = head;
        
        while (true) {
            do {
                if (p1 == p3) {
                    return p3;
                }
                p1 = p1->next;
            } while(p1 != p2);
            p3 = p3->next;
        }
    }
};
// prefix + cycle
// 2t - t = k * cycle 
// t = prefix + x
// 2t = prefix + k * cycle + x
// tt = prefix
// z*tt = prefix + kk * cycle
// z=1+kk*cycle/prefix
