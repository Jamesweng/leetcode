class Solution {
private:
    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool solve(vector<vector<char>>& board, string& word, int index, int x, int y) {
        if (index == word.size()) return true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() &&
               board[nx][ny] == word[index]) {
                board[nx][ny] += 'Z';
                if (solve(board, word, index + 1, nx, ny)) return true;
                board[nx][ny] -= 'Z';
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    board[i][j] += 'Z';
                    if (solve(board, word, 1, i, j)) {
                        return true;
                    }
                    board[i][j] -= 'Z';
                }
            }
        }
        return false;
    }
};
