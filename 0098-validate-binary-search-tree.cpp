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
    bool walk(TreeNode* node, int& min_val, int &max_val) {
        min_val = max_val = node->val;
        if (node->left) {
            int left_min_val, left_max_val;
            if (!walk(node->left, left_min_val, left_max_val)) return false;
            if (left_max_val >= node->val) return false;
            if (left_min_val < min_val) min_val = left_min_val;
            if (left_max_val > max_val) max_val = left_max_val;
        }
        if (node->right) {
            int right_min_val, right_max_val;
            if (!walk(node->right, right_min_val, right_max_val)) return false;
            if (right_min_val <= node->val) return false;
            if (right_min_val < min_val) min_val = right_min_val;
            if (right_max_val > max_val) max_val = right_max_val;
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        int min_val, max_val;
        return walk(root, min_val, max_val);
    }
};
