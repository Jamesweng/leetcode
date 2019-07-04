/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int len(ListNode* head, ListNode*& tail) {
        int n = 0;
        while (head != NULL) tail = head, head = head->next, n++;
        return n;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        
        ListNode* tail = NULL;
        int n = len(head, tail);
        k %= n;
        
        if (k == 0) return head;
        
        ListNode* p1 = head;
        for (int x = n - k - 1; x > 0; x--) p1 = p1->next;
        
        ListNode* newHead = p1->next;
        tail->next = head;
        p1->next = NULL;
        return newHead;
    }
};
