class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool f[s.size() + 1];
        for (int i = 0; i <= s.size(); ++i) {
            if (i == 0) f[i] = true;
            else {
                f[i] = false;
                for (int j = 0; j < wordDict.size(); ++j) {
                    string& word = wordDict[j];
                    if (word.size() > i || !f[i - word.size()]) continue;
                    if (s.substr(i - word.size(), word.size()) == word) {
                        f[i] = true;
                        break;
                    }
                }
            }
        }
        return f[s.size()];
    }
};
