class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x < 10) {
            return true;
        } else {
            int stk[20];
            int top = 0;
            while (x > 0) {
                stk[top++] = x % 10;
                x /= 10;
            }
            for (int i = 0; i < top; ++i) {
                int j = top - i - 1;
                if (i >= j) break;
                if (stk[i] != stk[j]) {
                    return false;
                }
            }
            return true;
        }
    }
};
