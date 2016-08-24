int* countBits(int num, int* returnSize) {
    *returnSize = ++num;
    int* result = (int*)malloc(num*sizeof(int));
    result[0] = 0;
    for(int i = 1; i < num; i++) {
        if (i % 2 == 1) result[i] = result[i - 1] + 1; // odd
        else result[i] = result[i / 2]; // even
    }
    return result;
}