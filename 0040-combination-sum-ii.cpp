class Solution {
public:
    vector<vector<int>> ans;
    map<int, int> counts;
    void solve(vector<pair<int,int>>& nums, int sum, int index, vector<int>& cur) {
        if (sum == 0) {
            ans.push_back(cur);
            return;
        }
        if (index >= nums.size()) return;        
        solve(nums, sum, index + 1, cur);
        
        pair<int,int> p = nums[index];
        int old_size = cur.size();
    
        for (int i = 0; i < p.second && sum >= p.first; ++i) {
            cur.push_back(p.first);
            sum -= p.first;
            solve(nums, sum, index + 1, cur);
        }
        
        while(cur.size() > old_size) cur.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        counts.clear();
        for (int i = 0; i < candidates.size(); ++i) {
            int p = candidates[i];
            if (counts.find(p) == counts.end()) counts[p] = 1;
            else counts[p]++;
        }
        vector<pair<int,int>> nums;
        for (map<int,int>::iterator it = counts.begin();
            it != counts.end(); ++it) {
            nums.push_back(make_pair(it->first, it->second));
        }
        
        ans.clear();
        vector<int> cur;
        solve(nums, target, 0, cur);
        return ans;
    }
};
