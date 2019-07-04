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
    vector<int> ans;
    void solve(TreeNode* node) {
        if (node->left != NULL) solve(node->left);
        ans.push_back(node->val);
        if (node->right != NULL) solve(node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        ans.clear();
        if (root != NULL) solve(root);
        return ans;
    }
};
