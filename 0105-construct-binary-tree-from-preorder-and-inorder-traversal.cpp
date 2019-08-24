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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int i, int j, int len) {
        if (len <= 0) return NULL;
        TreeNode* node = new TreeNode(preorder[i]); 
        for (int x = j; x < j + len; ++x) {
            if (inorder[x] == preorder[i]) {
                node->left = buildTree(preorder, inorder, i + 1, j, x - j);
                node->right = buildTree(preorder, inorder, i + 1 + (x - j), x + 1, j + len - x - 1);
                break;
            }
        }
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, 0, preorder.size());
    }
};
