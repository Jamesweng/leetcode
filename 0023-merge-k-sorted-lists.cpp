/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool comp(const ListNode* a, const ListNode* b) {
    return a->val > b->val;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> heaps;
        for (int i = 0; i < lists.size(); ++i) {
            ListNode* h = lists[i];
            if (h == NULL) continue;
            heaps.push_back(h);
            push_heap(heaps.begin(), heaps.end(), comp);
        }
        ListNode* ans = NULL, *p = NULL;
        while (heaps.size() > 0) {
            pop_heap(heaps.begin(), heaps.end(), comp);
            ListNode*& h = heaps.back();
            
            if (ans == NULL) {
                ans = h;
                p = h;
            } else {
                p->next = h;
                p = p->next;
            }
            
            h = h->next;
            if (h != NULL) {
                push_heap(heaps.begin(), heaps.end(), comp);
            } else {
                heaps.pop_back();
            }
        }
        
        return ans;
    }
};
