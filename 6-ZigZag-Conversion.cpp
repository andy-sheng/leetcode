class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string result = "";
        int length = s.length();
        int maxGap = (numRows - 1) * 2;
        for (int row = 0; row < numRows && row < length; row++) {
            int gap = (numRows - 1 - row) * 2;
            gap = (gap == 0) ? maxGap : gap;
            result = result + s[row];
            int position = row + gap;
            while (position < length) {
                result = result + s[position];
                gap = (gap != maxGap) ? maxGap - gap : gap;
                position = position + gap;
            }
        }
        return result;
    }
    
};