class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        int n = matrix.size(), m = matrix[0].size();
        int upperOnes[n][m], leftMost[n][m], rightMost[n][m];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '0') {
                    upperOnes[i][j] = 0;
                    leftMost[i][j] = 0;
                } else {
                    upperOnes[i][j] = 1;
                    if (i > 0) upperOnes[i][j] += upperOnes[i - 1][j];
                    leftMost[i][j] = j;
                    for (int p = j - 1; p >= 0 && upperOnes[i][p] >= upperOnes[i][j]; ) {
                        leftMost[i][j] = leftMost[i][p];
                        p = leftMost[i][p] - 1;
                    }
                }
            }
            for (int j = m - 1; j >= 0; --j) {
                if (matrix[i][j] == '0') {
                    rightMost[i][j] = 0;
                } else {
                    rightMost[i][j] = j;
                    for (int p = j + 1; p < m && upperOnes[i][p] >= upperOnes[i][j]; ) {
                        rightMost[i][j] = rightMost[i][p];
                        p = rightMost[i][p] + 1;
                    }
                }
                
                int h = upperOnes[i][j];
                if (h == 0) continue;
                int w = rightMost[i][j] - leftMost[i][j] + 1;
                if (h * w > ans) ans = h * w;
            }
        }
        
        return ans;
    }
};
