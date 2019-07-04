class Solution {
private:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    void fill(vector<vector<int>>& matrix, int x, int y, int k, int v) {
        matrix[x][y] = v;
        if (v == matrix.size() * matrix.size()) return;
        int nx = x + dir[k][0];
        int ny = y + dir[k][1];
        if (nx >= 0 && nx < matrix.size() &&
           ny >= 0 && ny < matrix.size() &&
           matrix[nx][ny] == 0) {
            fill(matrix, nx, ny, k, v + 1);
        } else {
            fill(matrix, x, y, (k + 1) % 4, v);
        }
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        for (int i = 0; i < n; ++i) {
            matrix.push_back(vector<int>());
            vector<int>& vec = matrix.back();
            for (int j = 0; j < n; ++j) {
                vec.push_back(0);
            }
        }
        fill(matrix, 0, 0, 0, 1);
        return matrix;
    }
};
