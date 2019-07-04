class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[255];
        memset(pos, 0, sizeof(pos));
        
        int ans = 0;
        int agg = 0;
        int lastM = 0;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (pos[ch] == 0 || pos[ch] < lastM) {
                agg += 1;
                if (agg > ans) {
                    ans = agg;
                }
            } else {
                int cur = i - (pos[ch] - 1);
                if (cur > ans) {
                    ans = cur;
                }
                agg = cur;
                lastM = pos[ch];
            }
            
            pos[ch] = i + 1;
        }
        
        return ans;
    }
};
