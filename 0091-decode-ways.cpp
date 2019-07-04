class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        
        int n = s.size();
        int f[n + 1];
        f[n] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                f[i] = 0;
                continue;
            } 
            if (i == n - 1) {
                f[i] = 1;
            } else {
                f[i] = f[i + 1];
                if (i + 2 <= n) {
                    int v = (s[i] - '0') * 10 + s[i + 1] - '0';
                    if (v <= 26) {
                        f[i] += f[i + 2];
                    }
                }
            }
        }
        
        return f[0];
    }
};
