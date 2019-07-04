class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        
        if (s.empty()) return "";
        else if (s.size() == 1) return s;
        else if (numRows == 1) return s;
        
        for (int i = 0; i < numRows; ++i) {
            int odd = 1;
            for (int j = i; j < s.size(); ) {
                ans += s[j];
                
                if (i == 0 || i == numRows - 1) {
                    j += (numRows + numRows - 2);   
                } else {
                    if (odd) {
                        j += (numRows - i - 1) * 2;
                    } else {
                        j += (i + i);
                    }
                    
                    odd = 1 - odd;
                }
            }
        }
        
        return ans;
    }
};
