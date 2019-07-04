class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[m][n];
        // f[i][j] = 0,0 -> i,j
        // f[0][j] = f[0][j - 1] = 1
        // f[i][0] = 1
        // f[i][j] = f[i - 1][j] + f[i][j - 1]
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) f[i][j] = 1;
                else {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
};
