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
    TreeNode* buildTree(vector<int>& nums, int begin, int end) {
        if (begin > end) return NULL;
        
        int mid = (begin + end) / 2;
        
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildTree(nums, begin, mid - 1);
        node->right = buildTree(nums, mid + 1, end);
        return node;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};
