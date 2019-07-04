class Solution {
private:
    bool str_equal(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
    
    int n;
    char *f;
    // remember calculated state <i,j,len>
    bool isScramble(const string &s1, int i, 
                    const string &s2, int j, int len) {
        if (len == 1) {
            return s1[i] == s2[j];
        }
        
        int index = (i * n + j) * n + len - 1;
        if (f[index] != -1) return f[index];
        
        for (int x = i + 1; x < i + len; ++x) {
            int leftLen = x - i;
            int rightLen = i + len - x;
            string s1Left = s1.substr(i, leftLen);
            string s1Right = s1.substr(x, rightLen);
            
            string s2Left = s2.substr(j, leftLen);
            string s2Right = s2.substr(j + leftLen, rightLen);
            
            if (str_equal(s1Left, s2Left) && str_equal(s1Right, s2Right) &&
               isScramble(s1, i, s2, j, leftLen) &&
               isScramble(s1, x, s2, j + leftLen, rightLen)) {
                return f[index] = true;
            }
            
            string s2SwapLeft = s2.substr(j + len - leftLen, leftLen);
            string s2SwapRight = s2.substr(j, rightLen);
            if (str_equal(s1Left, s2SwapLeft) && str_equal(s1Right, s2SwapRight) &&
               isScramble(s1, i, s2, j + len - leftLen, leftLen) &&
               isScramble(s1, x, s2, j, rightLen)) {
                return f[index] = true;
            }
        }
        return f[index] = false;
    }
public:
    bool isScramble(string s1, string s2) {
        n = s1.size();
        f = new char[n * n * n];
        memset(f, 0xff, sizeof(char) * n * n * n);
        bool ans = isScramble(s1, 0, s2, 0, n);
        delete[] f;
        return ans;
    }
};
