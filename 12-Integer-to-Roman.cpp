class Solution {
public:
    string dic1[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string dic2[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string dic3[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string dic4[4] = {"", "M", "MM", "MMM"};
    string intToRoman(int num) {
        string result = "";
        result += dic4[num / 1000];
        num %= 1000;
        result += dic3[num / 100];
        num %= 100;
        result += dic2[num / 10];
        num %= 10;
        result += dic1[num / 1];
        return result;
        
    }
};