class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        auto prevInc = false;
        
        for (auto step = 1, pos = 0; ;) {
            if (pos == 0 || nums[pos] > nums[pos - 1]) {
                if (pos == n - 1|| nums[pos] > nums[pos + 1]) {
                    return pos;
                }
                if (prevInc) {
                    step *= 2;
                } else {
                    step = 1;
                    prevInc = true;
                }
                
                pos += step;
                pos = min(n - 1, pos);
            } else {
                prevInc = false;
                pos -= step;
                pos = max(0, pos);
            }
        }
        
        return 0;
    }
};
