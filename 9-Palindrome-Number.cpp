class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int tmp = x;
        int reverse = 0;
        while (tmp != 0) {
            reverse = tmp % 10 + reverse * 10;
            tmp = tmp / 10;
        }
        if (x == reverse) {
            return true;
        } else {
            return false;
        }
    }
    
};