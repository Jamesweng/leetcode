class Solution {
public:
    int divide(int dividend, int divisor) {
        int factor = 1;
        int a = 0;
        
        if (divisor == 0x80000000) {
            if (dividend == 0x80000000) return 1;
            else return 0;
        }
        
        if (dividend > 0) {
            if (divisor < 0) {
                factor = -1;
                divisor = -divisor;
            }
        } else {
            if (dividend == 0x80000000) {
                dividend++;
                a = 1;
            }
            
            dividend = -dividend;
            if (divisor > 0) {
                factor = -1;
            } else {
                divisor = -divisor;
            }
        }
        
        int ans = 0;
        while (dividend >= divisor) {
            int c = divisor;
            int x = 1;
            
            while (dividend > c) {
                if (c > dividend - c) break;
                c += c;
                x += x;
            }
            dividend -= c;
            ans += x;
        }
        if (dividend >= divisor - a) {
            if (ans == 0x7fffffff) {
                return factor == 1 ? 0x7fffffff : 0x80000000;
            }
            ans += 1;
        }
        return ans * factor;
    }
};
