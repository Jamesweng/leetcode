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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        queue<TreeNode*> que({root});
        
        for (int level = 0; !que.empty(); level++) {
            for (int size = que.size(); size > 0; size--) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (size == 1) ans.push_back(node->val);
            }
        }
        
        return ans;
    }
};
