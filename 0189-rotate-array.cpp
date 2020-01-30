class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1) return;
        vector<int> old(nums);
        k %= nums.size();
        for (int i = nums.size() - 1; i >= 0; --i) {
            nums[i] = old[((i - k) + nums.size()) % nums.size()];
        }
    }
};
