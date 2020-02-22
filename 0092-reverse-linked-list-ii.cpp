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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode vh(0);
        vh.next = head;
        head = &vh;
        m++;
        n++;
        
        ListNode* p1 = head, *p2 = head->next, *px, *py;
        // 1->2->..->m-1->m->m+1->...->n-1->n->n+1->...
        // 1->2->..->m-1->n->n-1->...->m+1->m->n+1->...
        // px: node m-1, py: node m, p1: prev node, p2: current node
        for (int j = 2; p2 != NULL && j <= n; j++) {
            if (m < j && j <= n) {
                if (j == n) {
                    px->next = p2;
                    py->next = p2->next;
                }
                ListNode* p3 = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = p3;
            } else {
                if (m == j) {
                    px = p1;
                    py = p2;
                }
                p1 = p2;
                p2 = p2->next;
            }
        }
        
        return vh.next;
    }
};
