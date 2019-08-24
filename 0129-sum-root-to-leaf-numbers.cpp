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
    void sumTrees(TreeNode*root, int cur, int& sum) {
        if (!root) return;
        cur = cur * 10 + root->val;
        if (!root->left && !root->right) sum += cur;
        else {
            if (root->left) sumTrees(root->left, cur, sum);
            if (root->right) sumTrees(root->right, cur, sum);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sumTrees(root, 0, sum);
        return sum;
    }
};
