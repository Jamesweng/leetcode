class Solution {
private:
    vector<vector<int>> ans;
    int N;
    void solve(vector<pair<int, int>>& counts, vector<int>& cur) {
        if (cur.size() == N) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < counts.size(); ++i) {
            pair<int, int> p = counts[i];
            if (p.second > 0) {
                counts[i].second--;
                cur.push_back(p.first);
                solve(counts, cur);
                cur.pop_back();
                counts[i].second++;
            }
        }
    }    
public:
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        N = nums.size();
        map<int, int> ps;
        vector<pair<int, int>> counts;
        for (int i = 0; i < nums.size(); ++i) {
            int p = nums[i];
            if (ps.find(p) == ps.end()) {
                ps[p] = 1;
            } else {
                ps[p]++;
            }
        }
        for (map<int, int>::iterator it = ps.begin(); it != ps.end(); ++it) {
            counts.push_back(make_pair(it->first, it->second));
        }
        ans.clear();
        vector<int> cur;
        solve(counts, cur);
        return ans;
    }
};
