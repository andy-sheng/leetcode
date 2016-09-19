int integerReplacement(int n) {
    if (n == 2147483647) return 32; 
    if (n == 1) return 0;
    if (n % 2 == 0) return 1 + integerReplacement(n >> 1);//even
    int plusOne = 1 + integerReplacement(n + 1);
    int minusOne = 1 + integerReplacement(n - 1);
    return plusOne < minusOne ? plusOne : minusOne;
}