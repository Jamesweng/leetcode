class Solution {
public:
    int reverse(int x) {
        int sign = x >= 0 ? 1 : -1; 
        if (x < 0) x = -x; 
        int y = 0;
        while (x != 0) {
            y = y * 10 + x % 10; 
            x /= 10; 
        }   

        return sign * y;
    }   
};
