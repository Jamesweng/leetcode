class Solution {
public:
    int romanToInt(string s) {
        int val[255];
        memset(val, 0, sizeof(val));
        
        val['I'] = 1, val['V'] = 5, val['X'] = 10, val['L'] = 50, val['C'] = 100, val['D'] = 500, val['M'] = 1000;
        
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (i + 1 < s.size()) {
                char next_ch = s[i + 1];
                
                if (ch == 'I' && (next_ch == 'V' || next_ch == 'X')) {
                    ans += -1;
                } else if (ch == 'X' && (next_ch == 'L' || next_ch == 'C')) {
                    ans += -10;
                } else if (ch == 'C' && (next_ch == 'D' || next_ch == 'M')) {
                    ans += -100;
                } else {
                    ans += val[ch];
                }
            } else {
                ans += val[ch];
            }
        }
        
        return ans;
    }
};
