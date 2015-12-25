int removeDuplicates(int* nums, int numsSize) {
    int storePos = -1, forwardPos = 1;
    for (; forwardPos < numsSize; forwardPos++) {
        if (nums[forwardPos] != nums[forwardPos - 1]) {
            if (storePos != -1) {
                nums[storePos++] = nums[forwardPos];
            }
        } else {
            if (storePos == -1) {
                storePos = forwardPos;
            }
        }
    }
    return storePos == -1 ? numsSize : storePos;
}