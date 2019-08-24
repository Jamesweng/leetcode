class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n, m;
    void fill(vector<vector<char>>& board, int x, int y, char ch) {
        board[x][y] = ch;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
               board[nx][ny] == 'O') {
                fill(board, nx, ny, ch);
            }
        }
    }
    void replace(vector<vector<char>>& board, char a, char b) {
         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == a) board[i][j] = b;
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        
        n = board.size();
        m = board[0].size();
        
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') {
                fill(board, i, 0, 'Y');
            }
            if (board[i][m - 1] == 'O') {
                fill(board, i, m - 1, 'Y');
            }
        }
        for (int i = 0; i < m; ++i) {
            if (board[0][i] == 'O') {
                fill(board, 0, i, 'Y');
            }
            if (board[n - 1][i] == 'O') {
                fill(board, n - 1, i, 'Y');
            }
        }
        replace(board, 'O', 'X');
        replace(board, 'Y', 'O');
    }
};
