class Solution {
public:
    bool isMatch(string s, string p) {
        // f[i][j] -> s[0..i] ~ p[0..j]
        // f[0][0] = true
        // g[i][j] = or(f[0][j - 1] .. f[i][j - 1])
        // g[i][j] = g[i - 1][j] | f[i][j - 1]
        bool f[s.size() + 1][p.size() + 1];
        bool g[s.size() + 1][p.size() + 1];
        
        for (int i = 0; i <= s.size(); ++i) {
            for (int j = 0; j <= p.size(); ++j) {
                if (i == 0 && j == 0) {
                    f[i][j] = true;
                    g[i][j] = false;
                    continue;
                }
                if (j == 0) {
                    f[i][j] = false;
                    g[i][j] = g[i - 1][j];
                    continue;
                }
                if (i == 0) {
                    g[i][j] = f[i][j - 1];
                } else {
                    g[i][j] = g[i - 1][j] | f[i][j - 1];
                }
                if (p[j - 1] == '?') {
                    if (i > 0) {
                        f[i][j] = f[i - 1][j - 1];
                    } else {
                        f[i][j] = false;
                    }
                } else if (p[j - 1] == '*') {
                    f[i][j] = g[i][j];
                  //  f[i][j] = false;
                   // for (int k = i; k >= 0 && !f[i][j]; --k) {
                    //    f[i][j] |= f[k][j - 1];
                   // }
                } else {
                    if (i > 0 && s[i - 1] == p[j - 1]) {
                        f[i][j] = f[i - 1][j - 1];
                    } else {
                        f[i][j] = false;
                    }
                }
            }
        }
        
        return f[s.size()][p.size()];
    }
};
