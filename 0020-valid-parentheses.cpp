class Solution {
public:
    bool isValid(string s) {
        int top = 0;
        char stk[s.size() + 1];
        
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                stk[top++] = ch;
            } else {
                if (top > 0 && (ch == ')'  && stk[top - 1] == '(' ||
                           ch == ']' && stk[top - 1] == '[' ||
                            ch == '}' && stk[top - 1] == '{')) {
                    top--;
                } else {
                    return false;
                }
            }
        }
        
        return top == 0;
    }
};
