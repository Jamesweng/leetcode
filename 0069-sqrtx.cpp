class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int lo = 0, hi = x, ans = 0;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (mi != 0 && mi > x / mi) {
                hi = mi - 1;
            } else if (mi == 0 || mi < x / mi) {
                lo = mi + 1;
                ans = mi;
            } else {
                return mi;
            }
        }
        return ans;
    }
};
