class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool found = false;
        for (int i = nums.size() - 1; i - 1 >= 0; --i) {
            if (nums[i - 1] < nums[i]) {
                for (int j = nums.size() - 1; j >= i; --j) {
                    if (nums[j] > nums[i - 1]) {
                        swap(nums[i - 1], nums[j]);
                        break;
                    }
                }
                for (int j = i, k = nums.size() -1; j < k; ++j, --k) {
                    swap(nums[j], nums[k]);
                }
                found = true;
                break;
            }
        }
        if (!found) {
            for (int i = 0, j = nums.size() -1 ; i < j; ++i, --j) {
                swap(nums[i], nums[j]);
            }
        }
     //   1,2,4,3 -> 1,4,2,3 -> 1,4,3,2 -> 4,1,2,3
    }
};
