class Solution {
    
public:
    void gen(vector<string>& ans, string cur, int opening, int total) {
        if (total == 0) {
            ans.push_back(cur);
            return;
        }
        if (opening > 0) {
            gen(ans, cur + ')', opening - 1, total - 1);
        }
        if (total > opening) {
            gen(ans, cur + '(', opening + 1, total - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(ans, "", 0, n + n);
        return ans;
    }
};
