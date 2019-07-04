class Solution {
public:
    int MOD = 16769023;
    int hash_word(string& word) {
        int val = 0;
        for (int i = 0; i < word.size(); ++i) {
            val = ((val * 31) % MOD + word[i]) % MOD;
        }
        return val;
    }
    bool is_same(const vector<int>& a, const vector<int>& b) {
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;
        
        //sort(words.begin(); words.end());
        vector<int> hwords;
        set<int> hwords_set;
        for (int i = 0; i < words.size(); ++i) {
            hwords.push_back(hash_word(words[i]));
            hwords_set.insert(hwords.back());
        }
        sort(hwords.begin(), hwords.end());
        
        vector<int> hs;
        hs.resize(s.size());
        int len = words[0].size();
        
        int hi = 1;
        for (int i = 1; i < len; ++i) hi = (hi * 31) % MOD;
        
        int val = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i >= len) {
                val = (val - (s[i - len] * hi) % MOD + MOD) % MOD;
            }
            val = ((val * 31) % MOD + s[i]) % MOD;
            
            if (i >= len - 1) { 
                hs[i - len + 1] = val;
            }
        }
        
        for (int i = 0; i < hs.size(); ++i) {
            vector<int> candidates;
            if (hwords_set.find(hs[i]) == hwords_set.end()) continue;
            
            for (int j = i; j < hs.size() && j < i + len * words.size(); j += len) {
                candidates.push_back(hs[j]);
            }
            sort(candidates.begin(), candidates.end());
            
            if (is_same(hwords, candidates)) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
