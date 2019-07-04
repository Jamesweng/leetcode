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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* st = head;
        ListNode* last_st = NULL;
        ListNode* ans = NULL;
        
        while (st != NULL) {
            ListNode* p1 = st;
            ListNode* pk = p1;
            
            for (int i = 0; i < k - 1 && pk != NULL; ++i) {
                pk = pk->next;
            }
            if (pk == NULL) {
                if (last_st != NULL) {
                    last_st->next = st;
                }
                break;
            }
            
            if (ans == NULL) ans = pk;
            ListNode* prev = p1;
            ListNode* cur = p1->next;
            
            if (last_st != NULL) {
                last_st->next = pk;
            }
            
            last_st = st;
            st = pk->next;
            
            while (prev != pk) {
                ListNode* tmp = cur->next;
                cur->next = prev;
                if (prev == p1) {
                    prev->next = NULL;
                }
                prev = cur;
                cur = tmp;
            }
        }
        if (ans == NULL) ans = head;
        return ans;
    }
};
