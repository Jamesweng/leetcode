class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        if (nums.size() == 0) {
            return 0;
        }
        
        int j = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) {
                if (j == -1) {
                    j = i;
                }
            } else {
                if (j != -1 && j < i) {
                    nums[j] = nums[i];
                    nums[i] = val;
                    
                    
                ++j;
                    while (nums[j] != val && j < i) ++j;
                }
            }
        }
        
        if (j == -1) {
            return nums.size();
        } else {
            return j;
        }
    }
};
