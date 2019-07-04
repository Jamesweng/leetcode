class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& cur) {
        if (nums.empty()) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            int p = nums[i];
            cur.push_back(p);
            nums[i] = nums[nums.size() - 1];
            nums.pop_back();
            solve(nums, cur);
            nums.push_back(nums[i]);
            nums[i] = p;
            cur.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        solve(nums, cur);
        return ans;
    }
};
