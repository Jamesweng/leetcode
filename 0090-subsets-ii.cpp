class Solution {
private:
    vector<vector<int>> ans;
    void solve(vector<pair<int, int>> &counter, int index, vector<int>& cur) {
        if (index == counter.size()) {
            ans.push_back(cur);
            return;
        }
        
        solve(counter, index + 1, cur);
        for (int i = 0; i < counter[index].second; ++i) {
            cur.push_back(counter[index].first);
            solve(counter, index + 1, cur);
        }
        
        for (int i = 0; i < counter[index].second; ++i) cur.pop_back();
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        
        map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = 1;
            } else {
                mp[nums[i]] += 1;
            }
        }
        
        vector<pair<int, int>> counter;
        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            counter.push_back(make_pair(it->first, it->second));
        }
        
        ans.clear();
        vector<int> cur;
        solve(counter, 0, cur);
        
        return ans;
    }
};
