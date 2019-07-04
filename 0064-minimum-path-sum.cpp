class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int n = grid.size(), m = grid[0].size();
        int f[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) f[i][j] = grid[i][j];
                else if (i == 0) f[i][j] = (f[i][j - 1] + grid[i][j]);
                else if (j == 0) f[i][j] = f[i - 1][j] + grid[i][j];
                else {
                    f[i][j] = min(f[i][j - 1], f[i - 1][j]) + grid[i][j];
                }
            }
        }
        return f[n - 1][m - 1];
    }
};
