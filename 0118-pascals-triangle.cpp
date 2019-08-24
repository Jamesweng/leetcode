class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for (int i = 1; i <= numRows; ++i) {
            vector<int> newRow;
            for (int j = 0; j < i; ++j) {
                if (j == 0 || j == i - 1) {
                    newRow.push_back(1);
                } else {
                    newRow.push_back(ans.back()[j - 1] + ans.back()[j]);
                }
            }
            
            ans.push_back(newRow);
        }
        
        return ans;
    }
};
