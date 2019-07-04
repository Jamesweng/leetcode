class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int n = matrix.size();
        int lo = 0, hi = n - 1, p = n;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (target <= matrix[mi][0]) {
                hi = mi - 1;
                p = mi; 
                if (matrix[p][0] == target) return true;
            } else {
                lo = mi + 1;
            }
        }
        
        p--;
        if (0 <= p && p < n) {
            return binary_search(matrix[p].begin(), matrix[p].end(), target);
        }
        return false;
    }
};
