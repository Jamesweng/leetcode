class Solution {
public:
    double fun(double x, int n) {
        if (n == 0) {
            return 1.;
        }
        if (n == 1) {
            return x;
        }
        double b = fun(x, n / 2);
        b *= b;
        if (n % 2 == 1) b *= x;
        return b;
    }
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (n == 0) {
            return 1.0;
        }
        double y = x;
        if (x < 0) x = -x;
        int m;
        double z = 1.0;
        if (n < 0) {
            if (n == -2147483648) {
                m = 2147483647;
                z = x;
            } else {
                m = -n;
            }
            
        } else {
            m = n;
        }
        double b = fun(x, m);
        b *= z;
        if (n < 0) b = 1.0 / b;
        if (y < 0) {
            if (n % 2 == 1) b = -b;
        }
        return b;
    }
};
// pow(x, n) = pow(x, n / 2) * pow(x, n / 2);
// if n % 2 == 0, *= x
