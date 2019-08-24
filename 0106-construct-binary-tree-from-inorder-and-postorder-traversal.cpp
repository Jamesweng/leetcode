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
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int i, int j, int len) {
        if (len <= 0) return NULL;
        TreeNode* node = new TreeNode(postorder[j + len - 1]);
        
        for (int x = i; x < i + len; ++x) {
            if (inorder[x] == postorder[j + len - 1]) {
                node->left = buildTree(inorder, postorder, i, j, x - i);
                node->right = buildTree(inorder, postorder, x + 1, j + x - i, len - (x - i) - 1);
                break;
            }
        }
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, 0, inorder.size());
    }
};
