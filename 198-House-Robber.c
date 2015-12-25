int rob(int* nums, int numsSize) {
    int tmp;
    if (numsSize == 0) {
        return 0;
    }
    if (numsSize >= 1 && nums[1] < nums[0]) {
        nums[1] = nums[0];
    }
    for (int i = 2; i < numsSize; i++) {
        tmp = nums[i - 2] + nums[i];
        if (tmp > nums[i - 1]) {
            nums[i] = nums[i - 2] + nums[i];
        } else {
            nums[i] = nums[i - 1];
        }
    }
    return nums[numsSize - 1];
}