class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == ' ') {
                cur = 0;
            } else {
                cur++;
                ans = max(cur, cur);
            }
        }
        return ans;
    }
};
