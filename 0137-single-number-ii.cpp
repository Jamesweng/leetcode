class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tracking_a = 0, tracking_b = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int for_tracking_b = tracking_a & nums[i];
            int to_reset = tracking_a & tracking_b & nums[i];
            tracking_a |= nums[i];
            tracking_b |= for_tracking_b;
            tracking_a ^= to_reset;
            tracking_b ^= to_reset;
        }
        return tracking_a;
    }
};
