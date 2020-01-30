class Solution {
private:
    int pow26[7] = {1, 26, 676, 17576, 456976, 11881376, 308915776};
    
public:
    int titleToNumber(string s) {
        int n = 1;
        
        for (int i = 1; i < s.size(); ++i) {
            n += pow26[i];
        }
        
        for (int i = 0; i < s.size(); ++i) {
            n += (s[i] - 'A') * pow26[s.size() - i - 1];
        }
        
        return n;
    }
};
