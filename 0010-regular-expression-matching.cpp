class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        
        bool** ans = new bool*[s.size() + 1];
        for (int i = 0; i <= s.size(); ++i) {
            ans[i] = new bool[p.size() + 1];
        }
        
        for (int j = 0; j <= p.size(); ++j) {
            for (int i = 0; i <= s.size(); ++i) {
                if (i == 0 && j == 0) {
                    ans[i][j] = true;
                } else if (i == 0) {
                    ans[i][j] = (j >= 2 && ans[i][j - 2] && p[j - 1] == '*') ;
                } else if (j == 0) {    
                    ans[i][j] = false;
                } else {
                    if (p[j - 1] == '.' || s[i - 1] == p[j - 1]) {
                        ans[i][j] = ans[i - 1][j - 1];
                    } else if (p[j - 1] == '*') {
                        ans[i][j] = false;
                        if (j >= 2) ans[i][j] = ans[i][j - 2];
                        for (int k = i; k >= 0; --k) {
                            if (k == 0) {
                                ans[i][j] |= ans[k][j - 2];
                            } else {
                                if (j >= 2 && (p[j - 2] == '.' || p[j - 2] == s[k - 1])) {
                                    ans[i][j] |= ans[k - 1][j - 2];
                                } else {
                                    break;
                                }
                            }
                        }
                    } else {
                        ans[i][j] = false;
                    }
                }
            }
        }
        
        bool ret = ans[s.size()][p.size()];
        
        
        for (int i = 0; i <= s.size(); ++i) {
            delete[] ans[i];
        }
        delete[] ans;
        
        return ret;
    }
};
