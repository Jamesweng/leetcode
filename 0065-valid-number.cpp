class Solution {
public:
    bool isNumber(string s) {
        string state = "begin";
        bool has_number = false;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\b') {
                if (state == "begin" || 
                   state == "end") {
                    continue;
                } else {
                    if (state == "left_number" || state == "right_number" ||
                       state == "mid_number" || (state == "left_dot" && has_number)) {
                        state = "end";
                        continue;
                    }
                    return false;
                }
            }
            
            if (ch == '-' || ch == '+') {
                if (state == "begin") {
                    state = "sign";
                    continue;
                } else if (state == "e") {
                    state = "esign";
                    continue;
                } else {
                    return false;
                }
            }
            
            if (ch == '.') {
                if (state == "begin" || state == "sign" || 
                   state == "left_number") {
                    state = "left_dot";
                    continue;
                } else {
                    return false;
                }
            }
            
            if ('0' <= ch && ch <= '9') {
                has_number = true;
                if (state == "begin" || state == "sign") {
                    state = "left_number";
                    continue;
                } else if (state == "left_dot") {
                    state = "mid_number";
                    continue;
                } else if (state == "e" || state == "esign") {
                    state = "right_number";
                    continue;
                } else if (state == "left_number" ||
                          state == "mid_number" ||
                          state == "right_number") {
                    continue;
                } else {
                    return false;
                }
            }
            
            if (ch == 'e') {
                if (state == "left_number" || state == "mid_number" ||
                   (state == "left_dot" && has_number)) {
                    state = "e";
                    continue;
                } else {
                    return false;
                }
            }
            
            return false;
        }
        
        if (state == "left_number" || state == "right_number" ||
            state == "mid_number" || (state == "left_dot" && has_number) ||
           state == "end") {
            return true;
        }
        
        return false;
    }
};
