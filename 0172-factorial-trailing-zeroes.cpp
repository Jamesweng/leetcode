class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long long p = 5;
        while (n >= p) {
            ans += n / p;
            p *= 5;
        }
        return ans;
    }
};
