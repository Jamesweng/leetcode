class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int* maxSum = new int[nums.size()];
        int ans = nums[0];
        
        for (int i = 0; i < nums.size(); ++i) {
            maxSum[i] = nums[i];
            if (i > 0 && maxSum[i - 1] > 0) {
                maxSum[i] += maxSum[i - 1];
            }
            
            ans = max(ans, maxSum[i]);
        }
        
        delete[] maxSum;
        return ans;
    }
};
