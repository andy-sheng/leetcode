int missingNumber(int* nums, int numsSize) {
    int tmp = 0;
    for (int i = 0; i < numsSize; i++) {
        tmp += nums[i];
    }
    return numsSize * (numsSize + 1) / 2 - tmp;
}