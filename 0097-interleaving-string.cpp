class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        
        if (s3.size() != n + m) return false;
        
        bool f[n + 1][m + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 && j == 0) {
                    f[i][j] = true;
                } else if (i == 0) {
                    f[i][j] = (s3[j - 1] == s2[j - 1]) && f[i][j - 1];
                } else if (j == 0) {
                    f[i][j] = (s3[i - 1] == s1[i - 1]) && f[i - 1][j];
                } else {
                    f[i][j] = ((s3[i + j - 1] == s2[j - 1]) && f[i][j - 1]) ||
                        (s3[i + j - 1] == s1[i - 1]) && f[i - 1][j];
                }
            }
        }
        
        return f[n][m];
    }
};
