int trailingZeroes(int n) {
    int five = 5, count = 0;
    while (n > 0) {
        n = n / five;
        count += n;
    }
    return count;
}