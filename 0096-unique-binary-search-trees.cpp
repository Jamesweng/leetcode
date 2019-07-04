class Solution {
public:
    int numTrees(int n) {
        int f[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == 1) f[i] = 1;
            else {
                f[i] = 0;
                for (int j = 1; j <= i; ++j) {
                    f[i] += f[j - 1] * f[i - j];
                }
            }
        }
        return f[n];
    }
};
// n = 2， 2
// 1
//  \
//  2

//  2
// /
//1
// f(n) = f(n - 1) * 2 + 1
