class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int REMOVED = 0x7ffff2ff;
        int cur, cnt;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == cur) {
                cnt++;
                if (cnt > 2) nums[i] = REMOVED;
            } else {
                cur = nums[i];
                cnt = 1;
            }
        }
        int n = nums.size();
        for (int i = 0, j = i + 1; i < nums.size(); ++i) {
            if (j < i + 1) j = i + 1;
            while (j < nums.size() && nums[j] == REMOVED) ++j;
            if (nums[i] == REMOVED) {
                if (j < nums.size()) {
                    swap(nums[i], nums[j]);
                    ++j;
                } else {
                    n = i;
                    break;
                }
            }
        }
        return n;
    }
};
