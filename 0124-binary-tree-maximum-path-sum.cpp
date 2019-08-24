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
    int ans;
    void maxPathSum(TreeNode* root, int parentMaxSumUp, int& maxSumUp, int& maxSumDown) {
        if (!root) {
            return;
        }
        
        maxSumUp = root->val;
        if (parentMaxSumUp > 0) {
            maxSumUp += parentMaxSumUp;
        }
        ans = max(ans, maxSumUp);
        
        maxSumDown = root->val;
        
        int leftMaxSumUp, leftMaxSumDown;
        int rightMaxSumUp, rightMaxSumDown;
        
        if (root->left) {
            maxPathSum(root->left, maxSumUp, leftMaxSumUp, leftMaxSumDown);
            maxSumDown = max(maxSumDown, root->val + leftMaxSumDown);
        }
        
        if (root->right) {
            maxPathSum(root->right, maxSumUp, rightMaxSumUp, rightMaxSumDown);
            maxSumDown = max(maxSumDown, root->val + rightMaxSumDown);
            
            if (root->left) {
                ans = max(ans, leftMaxSumDown + root->val + rightMaxSumDown);
            }
        }
        
        ans = max(ans, maxSumUp + maxSumDown - root->val);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        ans = root->val;
        int maxSumUp, maxSumDown;
        maxPathSum(root, 0, maxSumUp, maxSumDown);
        return ans;
    }
};
