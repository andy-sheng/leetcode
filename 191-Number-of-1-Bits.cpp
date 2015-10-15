class Solution {
public:
    int hammingWeight(uint32_t n) {
        int tmp = 0;
        while (n != 0) {
            if(n % 2 == 1) {
                tmp++;
            }
            n = n / 2;
        }
        return tmp;
    }
};