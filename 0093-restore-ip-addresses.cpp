class Solution {
private:
    char buf[32];
    vector<string> ans;
    void solve(string& s, int index, vector<int>& ip) {
        if (index == s.size()) {
            if (ip.size() == 4) {
                sprintf(buf, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
                ans.push_back(buf);
            }
            return;
        }
        
        if (ip.size() > 0) {
            int val = ip[ip.size() - 1], newval = val * 10 + s[index] - '0';
            if (val != 0 && newval <= 255) {
                ip[ip.size() - 1] = newval;
                solve(s, index + 1, ip);
                ip[ip.size() - 1] = val;
            }
        }
        
        if (ip.size() < 4) {
            ip.push_back(s[index] - '0');
            solve(s, index + 1, ip);
            ip.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        vector<int> ip;
        solve(s, 0, ip);
        return ans;
    }
};
