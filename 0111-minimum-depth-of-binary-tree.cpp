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
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int depth = 0x7fffffff;
        if (root->left) depth = minDepth(root->left);
        if (root->right) depth = min(depth, minDepth(root->right));
        if (depth != 0x7fffffff) return depth + 1;
        else return 1;
    }
};
