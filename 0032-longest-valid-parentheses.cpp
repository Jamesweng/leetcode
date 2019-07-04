class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        
        int stk[s.size()];
        int f[s.size()];
        
        int top = 0, ans = 0;
        for (int j = 0; j < s.size(); j++) {
            char ch = s[j];
            if (ch == ')') {
                if (top > 0) {
                    f[j] = stk[top - 1];
                    top--;
                } else {
                    top = 0;
                    f[j] = -1;
                }
            } else {
                stk[top] = j;
                top++;
                
                    f[j] = -1;
            }
        }

        for (int i = s.size() - 1; i >= 0; --i) {
            if (f[i] != -1) {
                int p = i, cur = 0;
                while (p > 0 && f[p] >= 0 && s[p] == ')') {
                    cur += (p - f[p] + 1);
                    p = f[p] - 1;   
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};
