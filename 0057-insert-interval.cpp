class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool inserted = false;
        for (int i = 0; i < intervals.size(); ++i) {
            vector<int>& cur = intervals[i];
            if (inserted) {
                ans.push_back(cur);
                continue;
            }
            
            if (newInterval[0] > cur[1]) {
                ans.push_back(cur);
            } else {
                if(cur[0] > newInterval[1]) {
                    inserted = true;
                    ans.push_back(newInterval);
                    ans.push_back(cur);
                } else {
                    newInterval[1] = max(newInterval[1], cur[1]);
                    newInterval[0] = min(newInterval[0], cur[0]);
                }
            }
        }
        if (!inserted) ans.push_back(newInterval);
        return ans;
    }
};
