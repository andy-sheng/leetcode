class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long n = digits.size() - 1;
        for (; n >= 0; n--) {
            digits[n] += 1;
            if (digits[n] != 10) {
                break;
            } else {
                digits[n] = 0;
            }
        }
        if (digits[0] == 0) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};