class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) return 0;
        int a = nums[0], b = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == a) b++;
            else {
                b--;
                if (b == 0) {
                    a = nums[i];
                    b = 1;
                }
            }
        }
        return a;
    }
};
