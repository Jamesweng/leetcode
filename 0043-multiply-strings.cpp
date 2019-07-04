class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int num3[num1.size() + num2.size()];
        memset(num3, 0, sizeof(num3));
        int len = num1.size() + num2.size() - 2;
        for (int i = 0; i < num2.size(); ++i) {
            int a = num2[i] - '0';
            int s = 0;
            if (a == 0) continue;
            for (int j = 0; j < num1.size(); ++j) {
                int b = num1[j] - '0';
                s += a * b;
                num3[i + j] += s % 10;
                s /= 10;
            }
            if (s > 0) {
                num3[i + num1.size()] = s;
                if (i == num2.size() - 1) len = num1.size() + num2.size() - 1;
            }
        }
        string ans = "";
        for (int i = 0; i < len; ++i) {
            if (num3[i] > 9) {
                num3[i + 1] += num3[i] / 10;
                num3[i] %= 10;
            }
            ans += ('0' + num3[i]);
        }
        if (num3[len] > 9) {
            num3[len + 1] += num3[len] / 10;
            num3[len] %= 10;
            ans += ('0' + num3[len]);
            ++len;
        }
        
        if (num3[len] != 0) {   
            ans += ('0' + num3[len]);
        }
        reverse(ans.begin(), ans.end());
        int st = ans.size() - 1;
        for (int i = 0; i < ans.size(); ++i) {
            if (ans[i] != '0') {
                st = i;
                break;
            }   
        }
        if (st > 0) ans = ans.substr(st);
        if (ans.empty()) ans = "0";
        return ans;
    }
};
/*
    123
    456
--------
    738
   615
  492
--------
  56088
*/
