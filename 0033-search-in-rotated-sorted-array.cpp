class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (nums[mi] == target) return mi;
            
            if (nums[mi] >= nums[lo]) {
                if (target > nums[mi]) {
                    lo = mi + 1;
                } else {
                    if (target >= nums[lo]) {
                        hi = mi - 1;    
                    } else {
                        lo = mi + 1;
                    }
                }   
            } else {
                if (target > nums[hi]) {
                    hi = mi - 1;
                } else {
                    if (target >= nums[mi]) {
                        lo = mi + 1;
                    } else {
                        hi = mi - 1;
                    }
                }
            }
        }
        
        return -1;
    }
};
