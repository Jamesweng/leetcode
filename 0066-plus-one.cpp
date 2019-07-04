class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits);
        reverse(ans.begin(), ans.end());
        ans[0] += 1;
        int s = 0;
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] += s;
            s = 0;
            if (ans[i] > 9) {
                s = 1;
                ans[i] %= 10;
            } else {
                break;
            }
        }
        if (s > 0) {
            ans.push_back(s);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
