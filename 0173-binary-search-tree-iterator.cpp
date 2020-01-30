/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<pair<TreeNode*, int>> stk;
    
public:
    BSTIterator(TreeNode* root) {
        if (root) {
            stk.emplace_back(root, 0);
        }
    }
    
    /** @return the next smallest number */
    int next() {
        auto& cur = stk.back();
        if (cur.second == 0) {
            if (cur.first->left) {
                cur.second = 1;
                stk.emplace_back(cur.first->left, 0);
                return next();
            } else {
                cur.second = 2;
                return cur.first->val;
            }
        } else if (cur.second == 1) {
            cur.second = 2;
            return cur.first->val;
        } else if (cur.second == 2) {
            cur.second = 3;
            if (cur.first->right) {
                stk.emplace_back(cur.first->right, 0);
                return next();
            } else {
                stk.pop_back();
                return next();
            }
        } else {
            stk.pop_back();
            return next();
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        while (!stk.empty()) {
            auto& cur = stk.back();
            if (cur.second == 2 && !cur.first->right ||
               cur.second == 3) {
                stk.pop_back();
            } else {
                break;
            }
        }
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
