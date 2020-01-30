class Solution {
private:
    int pow26[7] = {1, 26, 676, 17576, 456976, 11881376, 308915776};
    
    int calcLength(int n) {
        int acc = 0;
        for (int i = 1; i < 7; ++i) {
            if (n - pow26[i] <= acc) return i;
            acc += pow26[i];
        }
        return 7;
    }
    
public:
    string convertToTitle(int n) {
        string ans = "";
        int len = calcLength(n);
        for (int i = 1; i < len; ++i) {
            n -= pow26[i];
        }
        for (int i = 0; i < len; ++i) {
            int acc = 0;
            for (int j = 0; j < 26; ++j) {
                acc += pow26[len - i - 1];
                if (n <= acc) {
                    ans += 'A' + j;
                    n -= (acc - pow26[len - i - 1]);
                    break;
                }
            }
        }
        
        return ans;
    }
};
/*
len=1 -> 26
len=2 -> 26*26
*/
