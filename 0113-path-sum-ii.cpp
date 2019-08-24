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
    vector<vector<int>> ans;
    void walk(TreeNode* node, int sum, vector<int>& path) {
        if (!node) {
            return;
        }
        
        path.push_back(node->val);
        sum -= node->val;
        
        if (!node->left && !node->right) {
            if (!sum) ans.push_back(path);
        } else {
            if (node->left) walk(node->left, sum, path);
            if (node->right) walk(node->right, sum, path);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        ans.clear();
        walk(root, sum, path);
        return ans;
    }
};
