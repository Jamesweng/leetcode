class Solution {
public:
    int bs(vector<int>& nums, int p, bool lower_bound) {
        int lo = 0, hi = nums.size() - 1, ret = -1;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            
            if (nums[mi] > p) {
                hi = mi - 1;    
            } else if (nums[mi] < p) {
                lo = mi + 1;
            } else {
                ret = mi;
                if (lo == hi) break;
                if (lower_bound) hi = mi-1;
                else lo = mi+1;
                
            }
        }
        return ret;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int a = bs(nums, target, true);
        int b = bs(nums, target, false);
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
