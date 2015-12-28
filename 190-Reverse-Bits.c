uint32_t reverseBits(uint32_t n) {
    if (n == 0) {
        return 0;
    }
    int count = 0;
    uint32_t result = 0;
    while (n != 1) {
        count++;
        result = (result + n % 2) * 2;
        n /= 2;
    }
    result++;
    result *= pow(2, 31 - count);
    return result;
}