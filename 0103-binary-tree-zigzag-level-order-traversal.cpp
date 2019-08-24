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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> que[2];
        vector<vector<int>> ans;
        if (!root) return ans;
        
        que[0].push_back(root);
        int cur = 0;
        while (!que[cur].empty()) {
            int nxt = 1 - cur;
            vector<int> levels;
            while (!que[cur].empty()) {
                TreeNode* node;
                if (!cur) {
                    node = que[cur].front();
                    que[cur].pop_front();
                } else {
                    node = que[cur].back();
                    que[cur].pop_back();
                }
                levels.push_back(node->val);
                
                if (!cur) {
                    if (node->left) que[nxt].push_back(node->left);
                    if (node->right) que[nxt].push_back(node->right);
                } else {
                    if (node->right) que[nxt].push_front(node->right);
                    if (node->left) que[nxt].push_front(node->left);
                }
            }
            ans.push_back(levels);
            cur = 1 - cur;
        }
        
        return ans;
    }
};
