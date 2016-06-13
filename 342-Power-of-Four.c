bool isPowerOfFour(int num) {
    return num && (-num & num) == num && (num & 0xAAAAAAAA) == 0;
}