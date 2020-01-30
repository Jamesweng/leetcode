class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void fill(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && nx < grid.size() &&
               ny >= 0 && ny < grid[nx].size() &&
               grid[nx][ny] == '1') {
                fill(grid, nx, ny);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                char ch = grid[i][j];
                if (ch == '1') {
                    fill(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
