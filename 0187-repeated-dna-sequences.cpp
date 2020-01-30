class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        auto s2i = [](char ch) {
            if (ch <= 'C') return ch == 'A' ? 0 : 1;
            else return ch == 'G' ? 2 : 3;
        };
        
        auto i2s = [](int i) {
            if (i <= 1) return i == 0 ? 'A' : 'C';
            else return i == 2 ? 'G' : 'T';
        };
        
        unordered_set<int> hashes;
        unordered_set<int> hashAns;
        vector<string> ans;
        int hash = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            hash = ((hash << 2) | s2i(ch)) & 0xFFFFF;
            
            if (i < 9) continue;
            if (hashes.find(hash) != hashes.end()) {
                hashAns.insert(hash);
            } else {
                hashes.insert(hash);
            }
        }
        
        for (auto hash : hashAns) {
            string substr = "";
            for (int i = 18; i >=0; i -= 2) {
                char ch = i2s((hash >> i) & 3);
                substr += ch;
            }
            ans.emplace_back(substr);
        }
        
        return ans;
    }
};
