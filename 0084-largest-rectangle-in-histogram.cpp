class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        int n = heights.size();
        int leftMost[n], rightMost[n];
        for (int i = 0; i < n; ++i) {
            if (i == 0) leftMost[i] = i;
            else {
                leftMost[i] = i;
                int p = i - 1;
                for (; p >= 0 && heights[p] >= heights[i]; ) {
                    leftMost[i] = leftMost[p];
                    p = leftMost[p] - 1;
                }
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) rightMost[i] = i;
            else {
                rightMost[i] = i;
                int p = i + 1;
                for (; p < n && heights[p] >= heights[i]; ) {
                    rightMost[i] = rightMost[p];
                    p = rightMost[p] + 1;
                }
            }
            int w = rightMost[i] - leftMost[i] + 1;
            int h = heights[i];
            if (w * h > ans) ans = w * h;
        }
        return ans;
    }
};
