class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<pair<int,int>> hs;
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        
        for (int i = 0; i < vals.size(); ++i) {
            int a = vals[i];
            if (i > 0 && vals[i] == vals[i - 1]) continue;
            for (int j = i + 1, k = vals.size() - 1; j < k; ) {
                if (j > i + 1 && vals[j] == vals[j - 1]) { j++; continue; }
                int b = vals[j];
                int c = vals[k];
                if (b + c > -a) k--;
                else if (b + c < -a) j++;
                else {
                    vector<int> one;
                    one.push_back(a);
                    one.push_back(b);
                    one.push_back(c);
                    if (hs.find(make_pair(a, b)) == hs.end()) {
                        ans.push_back(one);
                        hs.insert(make_pair(a, b));
                    }
                    j++;
                }
            }
        }
            
        
        return ans;
    }
};
