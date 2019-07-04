class Solution {
public:
    int myAtoi(string str) {
        int state = 0;
        int sign = 1;
        int val = 0;
        double val_f = 0;
        for (int i = 0; i < str.size(); ++i) {
            char ch = str[i];
            if (state == 0) {
                if (ch == ' ') {
                    continue;
                } else {
                    state = 1;
                    --i;
                }
            } else if (state == 1) {
                if (ch == '+' || ch == '-') {
                    if (ch == '-') {
                        sign = -1;
                    }
                    state = 2;
                } else {
                    state = 2;
                    --i;
                }
            } else if (state == 2) {
                if (ch >= '0' && ch <= '9') {
                    
                    val_f = val_f * 10 + (ch - '0');
                    if (sign == -1) {
                        if (val_f * sign <= INT_MIN) {
                            return INT_MIN;
                        }
                    } else {
                        if (val_f >= INT_MAX) {
                            return INT_MAX;
                        }
                    }
                        val = val * 10 + (ch - '0');
                    
                    
                } else {
                    break;
                }
            }
        }
        val *= sign;
        val_f *= sign;
        if (val_f > INT_MAX) {
            val = INT_MAX;
        } else if (val_f < INT_MIN) {
            val = INT_MIN;
        }
        
        
        return val;
    }
};
