/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == NULL) return result;
        
        vector<TreeNode*> stk;
        stk.push_back(root);
        while (!stk.empty()) {
            TreeNode* p = stk.back();
            stk.pop_back();
            result.push_back(p->val);
            if (p->right) stk.push_back(p->right);
            if (p->left) stk.push_back(p->left);
        }
        
        return result;
    }
};
