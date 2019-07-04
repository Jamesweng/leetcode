static const int Mod37BitPosition[] = // map a bit value mod 37 to its position
{
  32, 0, 1, 26, 2, 23, 27, 0, 3, 16, 24, 30, 28, 11, 0, 13, 4,
  7, 17, 0, 25, 22, 31, 15, 29, 10, 12, 6, 0, 21, 14, 9, 5,
  20, 8, 19, 18
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = (1 << n) - 1; i >= 0; --i) {
            vector<int> cur;
            
            for (int v = i; v > 0; v &= (v - 1)) {
                int j = Mod37BitPosition[(-v & v) % 37];
                cur.push_back(nums[j]);
            }
            
            ans.push_back(cur);
        }
        return ans;
    }
};
