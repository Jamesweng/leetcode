class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int f[n], g[n], ans = 0, minPrice = 0x7fffffff;
        
        for (int i = 0; i < n; ++i) {
            if (i == 0) f[i] = 0;
            else {
                f[i] = max(f[i - 1], prices[i] - minPrice);
            }
            minPrice = min(minPrice, prices[i]);
            ans = max(ans, f[i]);
        }
        
        int maxPrice = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) g[i] = 0;
            else {
                g[i] = max(g[i + 1], maxPrice - prices[i]);
            }
            maxPrice = max(maxPrice, prices[i]);
            ans = max(ans, g[i]);
            
            if (i > 0) {
                ans = max(ans, f[i - 1] + g[i]);
            }
        }
        return ans;
    }
};
