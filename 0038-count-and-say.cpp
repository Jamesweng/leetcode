class Solution {
public:
    string countAndSay(int n) {
        string cur = "1", ans = cur;
        char buf[100];
        for (int i = 1; i < n; i++) {
            ans = "";
            int cnt = 1;
            for (int j = 0; j < cur.size(); ++j) {
                char ch = cur[j];
                if (j + 1 >= cur.size() || cur[j + 1] != ch) {
                    sprintf(buf, "%d", cnt);
                    ans += buf;
                    ans += ch;
                    cnt = 1;
                } else {
                    cnt++;
                }
            }
            cur = ans;
        }
        return ans;
    }
};
/*
1
    11
    21
    1211
    111221
    312211
    13112221
    1113213211
    31131211131221
    
    */
