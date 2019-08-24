class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        vector<int> result;
        for (int i = 0; i < tokens.size(); ++i) {
            string ch = tokens[i];
            if (ch == "+" || ch == "-" || 
                ch == "*" || ch == "/") {
                int b = result.back();
                result.pop_back();
                int a = result.back();
                result.pop_back();
                if (ch == "+") {
                    result.push_back(a + b);
                } else if (ch == "-") {
                    result.push_back(a - b);
                } else if (ch == "*") {
                    result.push_back(a * b);
                } else if (ch == "/") {
                    result.push_back(a / b);
                }
            } else {
                int a = atoi(ch.c_str());
                result.push_back(a);
            }
        }
        return result[0];
    }
};
