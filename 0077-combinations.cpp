class Solution {
private:
    vector<vector<int>> ans;
    void solve(int n, int k, vector<int>& cur) {
        if (k == 0) {
            ans.push_back(cur);
            return;
        }
        
        if (n == 0) {
            return;
        }
        
        solve(n - 1, k, cur);
        
        cur.push_back(n);
        solve(n - 1, k - 1, cur);
        cur.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        vector<int> cur;
        solve(n, k, cur);
        
        return ans;
    }
};
