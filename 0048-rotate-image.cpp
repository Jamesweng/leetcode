class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() <= 1) return;
        bool appended = false;
        if (matrix.size() % 2 == 0) {
            vector<int> zeros;
            zeros.push_back(0);
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i].push_back(0);
                
                for (int j = matrix[i].size() - 1; j > matrix[i].size() / 2; --j) {
                    swap(matrix[i][j], matrix[i][j - 1]);
                }
                zeros.push_back(0);
            }
            matrix.push_back(zeros);
            for (int i = matrix.size() - 1; i > matrix.size() / 2; --i) {
                swap(matrix[i], matrix[i - 1]);
            }
            appended = true;
        }
        
        int n = matrix.size();
        for (int j = 1; j <= n / 2; ++j) {
            for (int i = -j; i < j; ++i) {
                // -j, -i -> 
                int lx = -j + n / 2;
                int ly = n - 1 - (-i + n / 2);
                int tmp = matrix[ly][lx];
              //  printf("ly=%d,lx=%d\n", ly, lx);
                
                // i, -j
                int bx = i + n / 2;
                int by = n - 1 - (-j + n / 2);
                matrix[ly][lx] = matrix[by][bx];
                //printf("by=%d,bx=%d\n", by, bx);
                
              // j, i
                int rx = j + n / 2;
                int ry = n - 1 - (i + n / 2);
                matrix[by][bx] = matrix[ry][rx];
             // printf("ry=%d,rx=%d\n", ry,rx);
                
                // -i, j
                int tx = -i + n / 2;
                int ty = n - 1 - (j + n / 2);
                matrix[ry][rx] = matrix[ty][tx];
              //  printf("ty=%d,tx=%d\n", ty, tx);
                
                matrix[ty][tx] = tmp;
            }
        }
        
        if (appended) {
            for (int i = matrix.size() / 2; i + 1 < matrix.size(); ++i) {
                swap(matrix[i], matrix[i + 1]);
            }
            matrix.pop_back();
            for (int i = 0; i < matrix.size(); ++i) {
                for (int j = matrix[i].size() / 2; j + 1 < matrix[i].size(); ++j) {
                    swap(matrix[i][j], matrix[i][j + 1]);
                }
                matrix[i].pop_back();
            }
        }
    }
};
