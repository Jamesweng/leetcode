class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        
        int f[n];
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) f[i] = nums[i];
            else {
                f[i] = max(nums[i], f[i - 1]);
                if (i > 1) f[i] = max(f[i], nums[i] + f[i - 2]);
            }
        }
        return f[n - 1];
    }
};
