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
    vector<TreeNode*> ans;
    void genTrees(int minVal, int maxVal, vector<TreeNode*>& trees) {
        for (int rootVal = minVal; rootVal <= maxVal; ++rootVal) {
            vector<TreeNode*> leftTrees;
            vector<TreeNode*> rightTrees;
            if (minVal <= rootVal - 1) {
                genTrees(minVal, rootVal - 1, leftTrees);
            } else {
                leftTrees.push_back(NULL);
            }

            if (rootVal + 1 <= maxVal) {
                genTrees(rootVal + 1, maxVal, rightTrees);
            } else {
                rightTrees.push_back(NULL);
            }
            for (int i = 0; i < leftTrees.size(); ++i) {
                for (int j = 0; j < rightTrees.size(); ++j) {
                    TreeNode* newTree = new TreeNode(rootVal);
                    newTree->left = leftTrees[i];
                    newTree->right = rightTrees[j];
                    trees.push_back(newTree);
                }
            }
        }
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        ans.clear();
        genTrees(1, n, ans);
        return ans;
    }
};
