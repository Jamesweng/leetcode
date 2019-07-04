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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(0);
        ListNode* ans = sum;

        int val = 0;
        for (ListNode *p1 = l1, *p2 = l2; p1 != NULL || p2 != NULL; ) {
            
            if (p1 != NULL) {
               val += p1->val;
                p1 = p1->next;
            }
            if (p2 != NULL) {
                val += p2->val;
                p2 = p2->next;
            }
            
            sum->val = val % 10;
            val /= 10;
            
            if (p1 != NULL || p2 != NULL || val > 0) {
                sum->next = new ListNode(0);
                sum = sum->next;
            }
        }
        
        if (val != 0) {
            sum->val = val;
        }
        
        return ans;
    }
};
