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
    void walk(TreeNode* root, int depth, vector<pair<int, TreeNode*>>& sequence) {
        if (!root) return;
        walk(root->left, depth + 1, sequence);
        sequence.push_back(make_pair(depth, root));
        walk(root->right, depth + 1, sequence);
    }
public:
    bool isSymmetric(TreeNode* root) {
        vector<pair<int, TreeNode*>> sequence;
        walk(root, 1, sequence);
        for (int i = 0, j = sequence.size() - 1; i < j; ++i, --j) {
            if (sequence[i].first != sequence[j].first) return false;
            TreeNode *a = sequence[i].second, *b = sequence[j].second;
            
            if (a->val != b->val) return false;
            if (a->left && !b->right ||
               a->right && !b->left ||
               !a->left && b->right ||
               !a->right && b->left) return false; 
        }
        return true;
    }
};
