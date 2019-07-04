class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int f[n + 1][m + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 && j == 0) {
                    f[i][j] = 0;
                } else if (i == 0) {
                    f[i][j] = j;
                } else if (j == 0) {
                    f[i][j] = i;
                } else {
                    f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                    
                    char ch1 = word1[i - 1];
                    char ch2 = word2[j - 1];
                    if (ch1 == ch2) {
                        f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                    } else {
                        f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
                    }
                }
            }
        }
        return f[n][m];
    }
};
