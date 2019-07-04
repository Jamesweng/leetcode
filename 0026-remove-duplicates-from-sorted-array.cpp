class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int p = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[p]) {
                nums[++p] = nums[i];
            }
        }
        
        return p + 1;
    }
};
