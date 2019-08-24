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
    TreeNode* walk(TreeNode* node) {
        if (node == NULL) return NULL;
        if (node->left == NULL) {
            if (node->right == NULL) return node;
            return walk(node->right);
        }
        
        TreeNode* leftLast = walk(node->left);
        leftLast->right = node->right;
        node->right = node->left;
        node->left = NULL;
        
        if (leftLast->right == NULL) return leftLast;
        
        TreeNode* rightLast = walk(leftLast->right);
        return rightLast;
    }
    
public:
    void flatten(TreeNode* root) {
        walk(root);
    }
};
