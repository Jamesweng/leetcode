class Solution {
public:
    static bool cmp(const vector<int>&a, const vector<int>&b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.empty()) return ans;
        
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> cur = intervals[0];
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > cur[1]) {
                ans.push_back(cur);
                cur = intervals[i];
            } else {
                cur[1] = max(cur[1], intervals[i][1]);   
            }
        }
        
        ans.push_back(cur);
        return ans;
    }
};
