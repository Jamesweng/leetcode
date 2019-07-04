class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> slots;
        
        for (int i = 0; i < strs.size(); ++i) {
            string a = strs[i];
            sort(a.begin(), a.end());
            if (slots.find(a) == slots.end()) {
                vector<string> new_slot;
                new_slot.push_back(strs[i]);
                slots[a] = new_slot;
            } else {
                slots[a].push_back(strs[i]);
            }
        }
        vector<vector<string>> ans;
        
        for (map<string, vector<string>>::iterator it = slots.begin();
            it != slots.end(); it++) {
            ans.push_back(it->second);
        }
        
        return ans;
    }
};
