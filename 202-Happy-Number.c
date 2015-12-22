bool isHappy(int n) {
    int nArray[1000] = {0};
    int tmp = 0;
    int lastN = n;
    bool loop = false;
    while (n != 1) {
        tmp = 0;
        while (n != 0) {
            int tmpn = n % 10;
            tmp += tmpn * tmpn;
            tmpn = n % 10;
            n = n / 10;
        }
        n = tmp;
        if (nArray[n] == 1) { // loop
            return false;
        }
        nArray[n] = 1;
    }
    if (tmp == 1 || n == 1) {
        return true;
    } else {
        return false;
    }
}