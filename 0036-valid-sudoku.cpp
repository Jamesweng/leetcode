class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[10][10], col[10][10], box[10][10];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));
        
        bool ret = true;
        for (int i = 0; i < 9 && ret; i++) {
            for (int j = 0; j < 9 && ret; j++) {
                if (board[i][j] == '.') continue;
                int p = board[i][j] - '1';
                
                if (row[i][p]) ret = false;
                else {
                    row[i][p] = true;
                    if (col[j][p]) ret = false;
                    else {
                        col[j][p] = true;
                        
                        int q = (i / 3) * 3 + (j / 3);
                        
                        if (box[q][p]) ret = false;
                        else box[q][p] = true;
                    }
                }
            }
        }
        return ret;
    }
};
