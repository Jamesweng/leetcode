class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle.empty()) {
            return 0;
        }
        
        if (haystack.empty()) {
            return -1;
        }
        
        for (int i = 0; i < haystack.size(); ++i) {
            int j = 0;
            for ( j = 0; j < needle.size() && i + j < haystack.size(); ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};
