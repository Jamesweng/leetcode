class Solution {
private:
    vector< vector<string> >ans;
    vector<bool> calced;
    
    void solve(string& s, int ith, vector<string>& wordDict) {
        if (ith == s.size()) {
            return;
        }
        
        if (calced[ith]) return;
        calced[ith] = true;
        
        vector<string>& cur = ans[ith];
        
        for (int j = 0; j < wordDict.size(); ++j) {
            string& word = wordDict[j];
            if (ith + word.size() <= s.size() && 
                s.compare(ith, word.size(), word) == 0) {
                int nth = ith + word.size();
                solve(s, nth, wordDict);
                
                if (nth != s.size()) {
                    for (int k = 0; k < ans[nth].size(); ++k) {
                        cur.push_back(word + " " + ans[nth][k]);
                    }
                } else {
                    cur.push_back(word);
                }
            }
                
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ans.resize(s.size());
        calced.resize(s.size());
        solve(s, 0, wordDict);
        return ans[0];
    }
};
