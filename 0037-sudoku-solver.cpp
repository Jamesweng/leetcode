class Solution {
public:
    bool col[9][9], row[9][9], box[9][9];
    bool fill(vector<vector<char>>& board, int idx) {
        if (idx == 81) return true;
        
        int x = idx / 9, y = idx % 9;
        char p = board[x][y];
        if (p != '.') {
            return fill(board, idx + 1);
        } else {
            for (int i = 0; i < 9; ++i) {
                if (row[x][i] || col[y][i] || box[x / 3 * 3 + y / 3][i]) continue;
                
                row[x][i] = col[y][i] = box[x / 3 * 3 + y / 3][i] = true;
                board[x][y] = '1' + i;
                if (fill(board, idx + 1)) return true;
                board[x][y] = '.';
                row[x][i] = col[y][i] = box[x / 3 * 3 + y / 3][i] = false;
            }
            return false;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(col, 0, sizeof(col));
        memset(row, 0, sizeof(row));
        memset(box, 0, sizeof(box));
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                char p = board[i][j];
                if (p != '.') {
                    row[i][p - '1'] = true;
                    col[j][p - '1'] = true;
                    box[i / 3 * 3 + j / 3][p - '1'] = true;
                }
            }
        }
        
        fill(board, 0);
    }
};
