class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        if (strs.size() == 0) {
            return ans;
        }
        
        for (int i = 0; ; ++i) {
            char ch;
            for (int j = 0; j < strs.size(); ++j) {
                if (i >= strs[j].size()) {
                    return ans;
                }
                
                if (j == 0) {
                    ch = strs[j][i];
                } else if (strs[j][i] != ch) {
                    return ans;
                }
            }
            ans += ch;
        }
        
        return ans;
    }
};
