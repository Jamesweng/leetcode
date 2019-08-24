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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que[2];
        vector<vector<int>> ans;
        
        if (!root) return ans;
        
        int cur = 0;
        que[cur].push(root);
        
        while (!que[cur].empty()) {
            int nxt = 1 - cur;
            
            vector<int> vals;
            while (!que[cur].empty()) {
                TreeNode* t = que[cur].front();
                que[cur].pop();
                
                vals.push_back(t->val);
                
                if (t->left) que[nxt].push(t->left);
                if (t->right) que[nxt].push(t->right);
            }
            ans.push_back(vals);
            
            cur = 1 - cur;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
