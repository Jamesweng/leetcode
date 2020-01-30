class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k <= 0) return 0;
        
        if (k > n / 2) k = n / 2;
        
        int f[2][n], ans = 0;
        //printf("n=%d\n", n);
        // 前i个，k次交易最多的profit
        // f[k][i] = max(f[k - 1][j] + max{j..i})
        
        for (int kv = 0; kv <= k; ++kv) {
            int maxDiff = INT_MIN;
            for (int i = 0; i < n; ++i) {
                int x = kv % 2;
                if (kv == 0) f[x][i] = 0;
                else {
                    f[x][i] = 0;
                    
                    if (i == 0) continue;
                    
                    maxDiff = max(maxDiff, f[1 - x][i - 1] - prices[i - 1]);
                    f[x][i] = max(f[x][i - 1], maxDiff + prices[i]);
                    
//                     int maxPrice = prices[i], maxProfit = 0;
//                     for (int j = i - 1; j >= 0; --j) {
//                         maxProfit = max(maxProfit, maxPrice - prices[j]);
//                         maxPrice = max(maxPrice, prices[j]);

//                         f[x][i] = max(f[x][i], j > 0 ?
//                                        f[1 - x][j - 1] + maxProfit :
//                                       maxProfit);
//                     }
                }
                ans = max(ans, f[x][i]);
            }
        }
        
        return ans;
    }
};
