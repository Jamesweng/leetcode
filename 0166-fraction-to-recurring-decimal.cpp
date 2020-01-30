class Solution {

public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        
        int sign = 1;
        if ((long long)numerator * denominator < 0) {
            sign = -1;
        }
        long long a = numerator, b = denominator;
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        
        if (a >= b) {
            long long num = a / b;
            a %= b;
            ans = std::to_string(num);
        } else {
            ans = "0";
        }
        unordered_map<int, int> pos;
        
        bool dotted = false;
        for (int i = ans.size() + 1; a != 0; i++) {
            a *= 10;
            if (!dotted) {
                ans += ".";
                dotted = true;
            }
            if (pos.find(a) != pos.end()) {
                ans.insert(pos[a], "(");
                ans += ')';
                break;
            } else {
                pos[a] = i;
            }
            
            ans += std::to_string(a / b);
            a %= b;
        }
        
        if (sign == -1) ans.insert(0, "-");
        
        return ans;
    }
};
