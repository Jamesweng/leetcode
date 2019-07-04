class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size() + 1;
        
        while (true) {
            bool reduced = false;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= 0 || nums[i] > nums.size()) {
                    swap(nums[i], nums[nums.size() - 1]);
                    nums.pop_back();
                    --i;
                    reduced = true;
                }
            }
            if (!reduced) break;
        }
        if (nums.empty()) return 1;
        
        int bit_set[(nums.size() + 31) / 32];
        memset(bit_set, 0, sizeof(bit_set));

        for (int i = 0; i < nums.size(); ++i) {
            int p = nums[i];
            bit_set[p / 32] |= (1 << (p % 32));
        }
        
        for (int i = 1; i <= nums.size(); ++i) {
            if ((bit_set[i / 32] | (1 << (i % 32))) != bit_set[i / 32]) {
                return i;
            } 
        }
        
        return nums.size() + 1;
    }
};
// 1,2,5,6 ..1,2
// 1,1,2,2
