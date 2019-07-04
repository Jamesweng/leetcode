class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int k = 0, VISITED = 345672384;
        vector<int> ans;
        
        if (matrix.empty()) return ans;
        
        int x = 0, y = 0;
        int total = matrix.size() * matrix[0].size();
        while (ans.size() < total) {
            while (x < matrix.size() && 
                   y < matrix[0].size() && matrix[x][y] != VISITED) {
                ans.push_back(matrix[x][y]);
                matrix[x][y] = VISITED;
                x += dir[k][0];
                y += dir[k][1];
            }
            x -= dir[k][0];
            y -= dir[k][1];
            k = (k + 1) % 4;
            x += dir[k][0];
            y += dir[k][1];
        }
        
        return ans;
    }
};
