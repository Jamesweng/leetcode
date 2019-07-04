class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int start, int sum, vector<int>& cur) {
        if (sum == 0) {
            ans.push_back(cur);
            return;
        }
        if (start >= nums.size()) return;
        
        int oldsize = cur.size();
        int newsum = sum;
        int v = nums[start];
        for (int j = 0; newsum >= 0; ++j) {
            solve(nums, start + 1, newsum, cur);
            newsum -= v;
            cur.push_back(v);
        }
        while (cur.size() > oldsize) cur.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        ans.clear();
        solve(candidates, 0, target, cur);
        return ans;
    }
};
