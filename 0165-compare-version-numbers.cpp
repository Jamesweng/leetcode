class Solution {
private:
    vector<int> versionCode(string& version) {
        vector<int> versionCode;
        int cur = 0;
        for (auto ch : version) {
            if (ch == '.') {
                versionCode.push_back(cur);
                cur = 0;
            } else {
                cur = cur * 10 + (ch - '0');
            }
        }
        if (cur) versionCode.push_back(cur);
        return versionCode;
    }
public:
    int compareVersion(string version1, string version2) {
        auto v1 = versionCode(version1);
        auto v2 = versionCode(version2);
        
        while (v1.size() < v2.size()) v1.push_back(0);
        while (v1.size() > v2.size()) v2.push_back(0);
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] == v2[i]) continue;
            if (v1[i] > v2[i]) return 1;
            else return -1;
        }
        return 0;
    }
};

