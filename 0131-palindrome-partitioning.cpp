class Solution {
private:
    bool isWanted(string& str) {
        for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
    vector<vector<string>> ans;
    void solve(string &s, int ith, vector<string>& cur) {
        if (ith == s.size()) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = ith; i < s.size(); ++i) {
            string str = s.substr(ith, i - ith + 1);
            
            if (isWanted(str)) {
                cur.push_back(str);
                solve(s, i + 1, cur);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return ans;
        
        vector<string> cur;
        solve(s, 0, cur);
        
        return ans;
    }
};
