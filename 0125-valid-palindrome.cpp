class Solution {
private:
    bool isValid(char ch) {
        return 'a' <= ch && ch <= 'z' ||
            'A' <= ch && ch <= 'Z' ||
            '0' <= ch && ch <= '9';
    }
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ) {
            while (i < j && !isValid(s[i])) ++i;
            while (i < j && !isValid(s[j])) --j;
            
            if (i < j) {
                if (tolower(s[i]) == tolower(s[j])) {
                    i++, j--;
                } else {
                    return false;
                }
            } 
        }
        return true;
    }
};
