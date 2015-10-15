class Solution {
public:
    string dic[27] = {"Z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    string convertToTitle(int n) {
        string result = "";
        while (n != 0) {
            result = dic[n % 26] + result;
            if (n % 26 == 0) {
                n = n / 26 - 1;
            } else {
                n = n / 26;
            }
        }
        return result;
    }
    
};