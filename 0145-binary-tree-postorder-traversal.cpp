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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, bool>> stk;
        vector<int> ans;
        if (!root) return ans;
        stk.push(make_pair(root, false));
        
        while (!stk.empty()) {
            pair<TreeNode*, bool> node = stk.top();
            if (node.second) {
                ans.push_back(node.first->val);
                stk.pop();
            } else {
                stk.top().second = true;
                
                if (node.first->right) {
                    stk.push(make_pair(node.first->right, false));
                }
                if (node.first->left) {
                    stk.push(make_pair(node.first->left, false));
                }
            }
        }
        return ans;
    }
};
