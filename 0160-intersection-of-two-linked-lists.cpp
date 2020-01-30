/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int length(ListNode* head) {
        int len = 0;
        while (head) { len++, head = head->next; }
        return len;
    }
    ListNode* advance(ListNode* head, int k) {
        while (k--) head = head->next;
        return head;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA);
        int lenB = length(headB);
        ListNode* pA = headA, *pB = headB;
        if (lenA > lenB) {
            pA = advance(headA, lenA - lenB);
        } else if (lenA < lenB) {
            pB = advance(headB, lenB - lenA);
        }
        
        while (pA != pB && pA && pB) {
            pA = pA->next;
            pB = pB->next;
        }
        
        if (!pA || !pB) return NULL;
        else return pA;
    }
};
