void moveZeroes(int* nums, int numsSize) {
    int nonZeroPos = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 0) {
            nonZeroPos = nonZeroPos < i + 1 ? i + 1 : nonZeroPos;
            for(; nonZeroPos < numsSize; nonZeroPos++) {
                if(nums[nonZeroPos] != 0) {
                    nums[i] = nums[nonZeroPos];
                    nums[nonZeroPos++] = 0;
                    break;
                }
            }
        }
    }
}