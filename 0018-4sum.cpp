class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> vals = nums;
        vector<vector<int>> ans;
        sort(vals.begin(), vals.end());
        
        for (int i = 0; i < vals.size(); ++i) {
            int a = vals[i];
            if (i > 0 && vals[i - 1] == a) continue;
            for (int j = i + 1; j < vals.size(); ++j) {
                
                int b = vals[j];
                if (j > i + 1 && vals[j - 1] == b) continue;
                for (int k = j + 1, l = vals.size() - 1; k < l; ) {
                    int c = vals[k];
                    int d = vals[l];
                    if (k > j + 1 && vals[k - 1] == c) {k++; continue;}
                    int sum = a + b + c + d;
                    if (sum > target) l--;
                    else if (sum < target) k++;
                    else {
                        vector<int> cur;
                        cur.push_back(a);
                        cur.push_back(b);
                        cur.push_back(c);
                        cur.push_back(d);
                        ans.push_back(cur);
                        k++;
                    }
                }
            }
        }
        
        return ans;
    }
};
