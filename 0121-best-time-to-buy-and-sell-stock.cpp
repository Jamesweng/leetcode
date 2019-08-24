class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minPrice = 0x7fffffff;
        for (int i = 0; i < prices.size(); ++i) {
            ans = max(ans, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return ans;
    }
};
