/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* buildTree(ListNode* head, int length) {
        if (length <= 0) return NULL;
        int step = length / 2;
        ListNode*p = head;
        for (; p && step; p = p->next) step--;
        
        TreeNode* node = new TreeNode(p->val);
        node->left = buildTree(head, length / 2);
        node->right = buildTree(p->next, length - 1 - length / 2);
        return node;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int length = 0;
        for (ListNode* p = head; p; p = p->next) length++;
        return buildTree(head, length);
    }
};
