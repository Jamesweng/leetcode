class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string c = "";
        int s = 0;
        for (int i = 0; i < a.size() || i < b.size(); ++i) {
            if (i < a.size()) {
                s += (a[i] - '0');
            }
            if (i < b.size()) {
                s += (b[i] - '0');
            }
            c += ('0' + s % 2);
            s /= 2;
        }
        if (s > 0) {
            c += ('0' + s);
        }
        reverse(c.begin(), c.end());
        return c;
    }
};
