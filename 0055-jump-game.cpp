class Solution {
public:
    bool canJump(vector<int>& nums) {
        int rightMost = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int len = nums[i];
            rightMost = max(rightMost, i + len);
            if (rightMost >= nums.size() - 1) return true;
            if (len == 0 && rightMost == i) return false;
        }
        return false;
    }
};
