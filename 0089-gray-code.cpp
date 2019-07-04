class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> nGrayCodes;
        nGrayCodes.push_back(0);
        
        for (int i = 1; i <= n; ++i) {
            vector<int> newGrayCodes = nGrayCodes;
            
            for (int j = nGrayCodes.size() - 1; j >= 0; --j) {
                newGrayCodes.push_back((1 << (i - 1)) | nGrayCodes[j]);
            }
            
            nGrayCodes = newGrayCodes;
        }
        
        return nGrayCodes;
    }
};
/*
000
001
011
010
110
111
101
100
*/
