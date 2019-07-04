class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int TMP_ZERO = 0x7fff2fff;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < matrix.size(); ++k) {
                        if (matrix[k][j] != 0)
                            matrix[k][j] = TMP_ZERO;
                    }
                    for (int k = 0; k < matrix[i].size(); ++k) {
                        if (matrix[i][k] != 0)
                            matrix[i][k] = TMP_ZERO;
                    }
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == TMP_ZERO) matrix[i][j] = 0;
            }
        }
    }
};
