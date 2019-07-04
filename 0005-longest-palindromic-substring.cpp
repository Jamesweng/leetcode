class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        
        bool isValid[1001][600][2];
        int maxLen = 1;
        int cen = 0, type = 0;
        
        for (int len = 0; len + len <= s.size() + 1; ++len) {
            for (int i = 0; i < s.size(); ++i) {
                if (len == 0) {
                    isValid[i][len][0] = true;
                    isValid[i][len][1] = true;
                } else {
                    if (len == 1 || ((i - len + 1) >= 0 && (i + len - 1) < s.size()) &&
                        isValid[i][len - 1][0] && s[i - len + 1] == s[i + len - 1]) {
                        isValid[i][len][0] = true;
                        if (len > maxLen) {
                            maxLen = len;
                            cen = i, type = 0;
                        }
                    } else {
                        isValid[i][len][0] = false;
                    }
                    
                    if ((i - len + 1) >= 0 && (i + len) < s.size() && isValid[i][len - 1][1] && s[i - len + 1] == s[i + len]) {
                        isValid[i][len][1] = true;
                        if (len >= maxLen) {
                            maxLen = len;
                            cen = i, type = 1;
                        }
                    } else {
                        isValid[i][len][1] = false;
                    }
                }
            }    
        }
        string ans = "";
        if (type == 0) {
            for (int i = cen - maxLen + 1; i <= cen + maxLen - 1; ++i) {
                ans += s[i];
            }
        } else {
            for (int i = cen - maxLen + 1; i <= cen + maxLen; ++i) {
                ans += s[i];
            }
        }
        char buf[100];
        sprintf(buf, "%d,%d,%d", maxLen, cen, type);
        return ans;
    }
};
