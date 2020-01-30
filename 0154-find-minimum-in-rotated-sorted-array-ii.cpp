class Solution {
private:
    int findMin(vector<int>& nums, int begin, int end) {
        if (begin == end) {
            return nums[begin];
        } else if (begin + 1 == end) {
            return min(nums[begin], nums[end]);
        }
        if (nums[begin] < nums[end]) return nums[begin];
        
        int mid = (begin + end) / 2;
        if (nums[begin] < nums[mid]) {
            return findMin(nums, mid, end);
        } else if (nums[mid] < nums[end]) {
            return findMin(nums, begin, mid);
        } else {
            // nums[mid] <= nums[begin] && nums[mid] >= nums[end]
            while (begin < mid && nums[mid] == nums[begin]) begin++;
            while (end > mid && nums[mid] == nums[end]) end--;
            
            return min(findMin(nums, begin, mid), findMin(nums, mid, end));
        }
    }
    
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }
};
