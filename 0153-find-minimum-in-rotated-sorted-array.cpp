class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int begin = 0, end = nums.size() - 1, ans = nums[0];
        while (begin < end) {
            int mid = (begin + end) / 2;
            
            ans = min(ans, nums[mid]);
            ans = min(ans, nums[end]);
            if (nums[begin] < nums[mid]) {
                begin = mid;
            } else {
                end = mid;
            }
        }
        
        return ans;
    }
};
