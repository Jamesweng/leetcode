class Solution {
private:
    void solve(vector<int>& candidates, string& ans, int k) {
        int n = candidates.size();
        
        if (k < 1) {
            for (int i = 0; i < n; ++i) {
                ans += ('0' + candidates[i]);
            }
            return;
        }
        
        int x = 1, n_times = 1;
        
        for (int i = 1; i <= n; ++i) {
            if (n_times * i > k) {
                x = i - 1;
                break;
            }
            
            n_times *= i;
        }
        for (int i = 0; i < n - x - 1; ++i) {
            ans += '0' + candidates[i];
        }
        
        ans += '0' + candidates[n - x - 1 + k / n_times];

        candidates.erase(candidates.begin() + n - x - 1 + k / n_times);
        candidates.erase(candidates.begin(), candidates.begin() + n - x - 1);
        solve(candidates, ans, k % n_times);
    }
    
public:
    string getPermutation(int n, int k) {
        vector<int> candidates;
        for (int i = 1; i <= n; ++i) {
            candidates.push_back(i);
        }
        
        string ans = "";
        solve(candidates, ans, k - 1);
        return ans;
    }
};
/*
1234
1243
1324
1342
1423
1432
2134
2143
2314
2341
k=9 -- 
3*2*1=6
2
*/
