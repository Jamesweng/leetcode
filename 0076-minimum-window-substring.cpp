class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";
       
        int t_counter[255], s_counter[255];
        memset(t_counter, 0, sizeof(t_counter));
        memset(s_counter, 0, sizeof(s_counter));
        
        int char_count = 0;
        for (int i = 0; i < t.size(); ++i) {
            char ch = t[i];
            if (t_counter[ch] == 0) char_count++;
            t_counter[ch]++;
        }
        
        string ans = "";
        int min_len = s.size() + 1, x = 0;
        
        for (int i = 0, j = 0; i < s.size() && j < s.size(); ) {
            for (; x < char_count && j < s.size(); j++) {
                char ch = s[j];
            
                s_counter[ch]++;
                if (t_counter[ch] == s_counter[ch]) {
                    x++;
                }
            }
            for (; x == char_count && i < s.size(); i++) {
                int len = j - i;
                if (len < min_len) {
                     min_len = len;
                     ans = s.substr(i, len);
                }
                
                char ch = s[i];
                s_counter[ch]--;
                if (t_counter[ch] && t_counter[ch] > s_counter[ch]) {
                    x--;
                }
            }
        }
        return ans;
    }
};
