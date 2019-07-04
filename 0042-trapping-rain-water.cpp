class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        
        int left_max[height.size()];
        for (int i = 0; i < height.size(); ++i) {
            if (i == 0) {
                left_max[i] = 0;
            } else {
                left_max[i] = max(left_max[i - 1], height[i - 1]);
            }
        }
        int ans = 0, right_max = 0;
        for (int i = height.size() - 1; i >= 0; --i) {
            if (i == height.size() - 1) {
                right_max = 0;
            } else {
                right_max = max(right_max, height[i + 1]);
            }
            int h = min(left_max[i], right_max);
            if (h > height[i]) {
                ans += (h - height[i]);
            }
        }
        return ans;
    }
};
