class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string maps[10] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>que[2];
        int p = 0, q = 1;
        for (int i = 0; i < digits.size(); ++i) {
            int idx = digits[i] - '1';
            string chars = maps[idx];
            
            if (i == 0) {
                for (int j = 0; j < chars.size(); ++j) {
                    que[p].push_back(string("") + chars[j]);
             
                }
            } else {
                while (que[q].size() > 0) {
                    string cur = que[q].back();
                    que[q].pop_back();
                    for (int j = 0; j < chars.size(); ++j) {
                        que[p].push_back(cur + chars[j]);
                    }
                }
            }
            p = 1 - p;
            q = 1 - q;
        }
        return que[q];
    }
};
