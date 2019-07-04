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
    void get_max(TreeNode* node, int& max_val, TreeNode*& max_node) {
        max_val = node->val;
        max_node = node;
        
        int left_max_val, right_max_val;
        TreeNode* left_max_node, *right_max_node;
        
        if (node->left) {
            get_max(node->left, left_max_val, left_max_node);
            if (left_max_val > max_val) {
                max_val = left_max_val;
                max_node = left_max_node;
            }
        }
        if (node->right) {
            get_max(node->right, right_max_val, right_max_node);
            if (right_max_val > max_val) {
                max_val = right_max_val;
                max_node = right_max_node;
            }
        }
    }
    void get_min(TreeNode* node, int& min_val, TreeNode*& min_node) {
        min_val = node->val;
        min_node = node;
        
        int left_min_val, right_min_val;
        TreeNode* left_min_node, *right_min_node;
        
        if (node->left) {
            get_min(node->left, left_min_val, left_min_node);
            if (left_min_val < min_val) {
                min_val = left_min_val;
                min_node = left_min_node;
            }
        }
        if (node->right) {
            get_min(node->right, right_min_val, right_min_node);
            if (right_min_val < min_val) {
                min_val = right_min_val;
                min_node = right_min_node;
            }
        }
    }
    
    void solve(TreeNode* node) {
        TreeNode* right_min_node, *left_max_node;
        int right_min_val, left_max_val;
        
        if (node->left) {
            get_max(node->left, left_max_val, left_max_node);
        }
        if (node->right) {
            get_min(node->right, right_min_val, right_min_node);
        }
        
        if (node->left == NULL) {
            if (node->right == NULL) {
                return;
            }
            
            if (node->val < right_min_val) {
                solve(node->right);
            } else {
                swap(node->val, right_min_node->val);
            }
        } else if (node->right == NULL) {
            if (node->val > left_max_val) {
                solve(node->left);
            } else {
                swap(node->val, left_max_node->val);
            }
        } else {
            if (node->val > right_min_val) {
                if (node->val < left_max_val) {
                    swap(left_max_node->val, right_min_node->val);
                } else {
                    swap(node->val, right_min_node->val);
                }
            } else if (node->val < left_max_val) {
                swap(node->val, left_max_node->val);
            } else {
                solve(node->left);
                solve(node->right);
            }
        }
    }
public:
    void recoverTree(TreeNode* root) {
        solve(root);
    }
};
