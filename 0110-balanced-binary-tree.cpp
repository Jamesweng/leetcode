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
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        if (leftDepth >= 0 && rightDepth >= 0 && 
            abs(leftDepth - rightDepth) <= 1) {
            return 1 + max(leftDepth, rightDepth);
        } else {
            return -1;
        }
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return getDepth(root) >= 0;
    }
};
