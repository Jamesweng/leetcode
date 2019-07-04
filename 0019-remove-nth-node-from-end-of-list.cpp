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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head, *p2 = head, *p0 = head;
        while (p2 != NULL) {
            if (n > 0) {
                n--;
                p2 = p2->next;
            } else {
                p2 = p2->next;
                if (p1 != head) p0 = p0->next;
                p1 = p1->next;
                
            }
        }
        if (p1 != head) {
            p0->next = p1->next;
        return head;
        } else {
            return head->next;
        }
    }
};
