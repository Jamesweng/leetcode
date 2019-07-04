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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode* p1 = head;
        ListNode* p2 = p1->next, *to_be_deleted = NULL;
        while (p2 != NULL) {
            if (p2->val != p1->val) {
                p1->next = p2;
                p1 = p2;
                to_be_deleted = NULL;
            } else {
                p1->next = NULL;
                to_be_deleted = p2;
            }
            p2 = p2->next;
            if (to_be_deleted != NULL) delete to_be_deleted;
        }
        return head;
    }
};
