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
    int len(ListNode* head) {
        if (!head) return 0;
        return 1 + len(head->next);
    }
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        
        int step = len(head) / 2;
        
        ListNode* p = head;
        for (int i = 0; i < step; ++i) {
            p = p->next;
        }
        
        ListNode* prev = p;
        p = p->next;
        prev->next = NULL;
        while (p != NULL) {
            ListNode* q = p->next;
            p->next = prev;
            prev = p;
            p = q;
        }
        
        ListNode* tail = prev;
        for (int i = 0; i < step; ++i) {
            ListNode* tmp = head->next;
            ListNode* tmp2 = tail->next;
            
            if (tmp == tail) {
                break;
            }
            head->next = tail;
            tail->next = tmp;
            head = tmp;
            tail = tmp2;
            
            if (tmp == tmp2) {
                tmp->next = NULL;
            }
        }
    }
};
