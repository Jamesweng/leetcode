class Solution {
private:
    bool isWanted(string str) {
        for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
public:
    int minCut(string s) {
        int f[s.size() + 1];
        
        for (int i = 0; i <= s.size(); ++i) {
            if (i == 0) f[i] = 0;
            else {
                f[i] = i;
                
                for (int j = i - 1; j >= 0; --j) {
                    int candidate = 0;
                    if (j > 0) candidate = f[j] + 1; 
                    if (candidate < f[i] && isWanted(s.substr(j, i - j))) {
                        f[i] = candidate;
                    }
                }
            }
        }
        
        return f[s.size()];
    }
};
