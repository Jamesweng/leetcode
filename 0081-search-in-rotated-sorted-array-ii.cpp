class Solution {
private:
    bool search(vector<int>& nums, int begin, int end, int target) {
        if (begin > end) return false;
        
        int mi = (begin + end) / 2;
        if (nums[mi] == target) return true;
            
        if (nums[mi] == nums[begin]) {
            return search(nums, begin, mi - 1, target) ||
                search(nums, mi + 1, end, target);
        }
        if (nums[mi] > nums[begin]) { //dangdiao
            if (target > nums[mi]) {
                return search(nums, mi + 1, end, target);
            } else {
                if (target >= nums[begin]) {
                    return search(nums, begin, mi - 1, target);
                } else {
                    return search(nums, mi + 1, end, target);
                }
            }   
        } else {
            if (target > nums[end]) {
                return search(nums, begin, mi - 1, target);
            } else {
                if (target >= nums[mi]) {
                    return search(nums, mi + 1, end, target);
                } else {
                    return search(nums, begin, mi - 1, target);
                }
            }
        }
    }
    
public:
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
};
