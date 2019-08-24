class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rows[2];
        int cur = 1;
        rows[0].push_back(1);
        
        for (int i = 0; i <= rowIndex; ++i) {
            rows[cur].clear();
            int lst = 1 - cur;
            
            for (int j = 0; j < i + 1; ++j) {
                if (j == 0 || j == i) {
                    rows[cur].push_back(1);
                } else {
                    rows[cur].push_back(rows[lst][j - 1] + rows[lst][j]);
                }
            }
            
            cur = 1 - cur;
        }
        
        return rows[1 - cur];
    }
};
