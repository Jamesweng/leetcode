class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        
        int ans = 0;
        int mins = 0x7fffffff;
        for (int i = 0; i < vals.size(); ++i) {
            int a = vals[i];
            for (int j = i + 1; j < vals.size(); ++j) {
                int b = vals[j];
                int c = target - a - b;
                
                int pos = lower_bound(vals.begin() + j + 1, vals.end(), c) - vals.begin();
                int cur;
                if (pos < vals.size()) {
                cur = abs(a + b + vals[pos] - target);
                if (cur < mins) {
                    mins = cur;
                    ans = a + b + vals[pos];
                }
                }
                
                if (pos > 0 && pos - 1 > j) {
                cur = abs(a + b + vals[pos - 1] - target);
                if (cur < mins) {
                    mins = cur;
                    ans = a + b + vals[pos - 1];
                }
                }
            }
        }
        
        return ans;
    }
};
