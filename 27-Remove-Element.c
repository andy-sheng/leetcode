int removeElement(int* nums, int numsSize, int val) {
    int frontPtr = 0, backPtr = numsSize - 1;
    while (frontPtr <= backPtr) {
        if (nums[frontPtr] == val) {
            numsSize--;
            while (backPtr > frontPtr && nums[backPtr] == val) {
                numsSize--;
                backPtr--;
            }
            if (backPtr > frontPtr) {
                nums[frontPtr] = nums[backPtr];
            } else {
                return numsSize;
            }
            backPtr--;
        }
        frontPtr++;
    }
    return numsSize;
}