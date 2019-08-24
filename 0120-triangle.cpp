class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        
        vector<int> minSum[2];
        minSum[0].resize(triangle.size());
        minSum[1].resize(triangle.size());
        
        int cur = 0, last = 1, ans = 0x7fffffff;
        for (int i = 0; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                minSum[cur][j] = triangle[i][j];
                if (i > 0) {
                    if (j == 0) minSum[cur][j] += minSum[last][j];
                    else if (j == triangle[i].size() - 1) minSum[cur][j] += minSum[last][j - 1];
                    else minSum[cur][j] += min(minSum[last][j], minSum[last][j - 1]);
                }
                if (i == triangle.size() - 1) ans = min(ans, minSum[cur][j]);
            }
            last = cur;
            cur = 1 - cur;
        }
        
        return ans;
    }
};
