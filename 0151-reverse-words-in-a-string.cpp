class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        vector<string> words;
        
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += ch;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        string ans = "";
        for (int i = words.size() - 1; i >= 0; --i) {
            ans += words[i];
            if (i > 0) ans += ' ';
        }
        return ans;
    }
};
