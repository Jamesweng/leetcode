class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        long long f[n], g[n], ans = nums[0];
        
        for (int i = 0; i < n; ++i) {
            f[i] = g[i] = nums[i];
            if (i > 0) {
                f[i] = max(f[i], f[i - 1] * nums[i]);
                f[i] = max(f[i], g[i - 1] * nums[i]);
                g[i] = min(g[i], g[i - 1] * nums[i]);
                g[i] = min(g[i], f[i - 1] * nums[i]);
            }
            ans = max(ans, f[i]);
        }
        
        return ans;
    }
};
