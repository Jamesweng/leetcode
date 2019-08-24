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
    void printList(const string& label, ListNode* head) {
        printf("%s ", label.c_str());
        for (ListNode* p = head; p; p = p->next) {
            printf("%d ", p->val);
        }
        printf("\n");
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return NULL;
        if (head->next == NULL) return head;
        
        int pivot = head->val;
        
        ListNode* p = head->next;
        head->next = NULL;
        
        ListNode* h1 = NULL, *h2 = NULL;
        ListNode* p1 = NULL, *p2 = NULL;
        for (; p != NULL; ) {
            ListNode* next = p->next;
            p->next = NULL;
            if (p->val <= pivot) {
                if (h1 == NULL) h1 = p, p1 = p;
                else p1->next = p, p1 = p;
            } else {
                if (h2 == NULL) h2 = p, p2 = p;
                else p2->next = p, p2 = p;
            }
            p = next;
        }
        
        h1 = sortList(h1);
        
        if (h1 == NULL) h1 = head;
        else {
            for (p = h1; p->next != NULL; p = p->next);
            p->next = head;
        }
        
        h2 = sortList(h2);
        
        if (h2) {
            head->next = h2;
        }
        
        return h1;
    }
};
