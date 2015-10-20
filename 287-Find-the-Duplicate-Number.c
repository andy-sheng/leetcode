int findDuplicate(int* nums, int numsSize) {
    int *arr = (int *)malloc(sizeof(int) * (numsSize));
    
    for (int i = 1; i < numsSize; i++) arr[i] = 0;
    for (int i = 0; i < numsSize; i++) arr[nums[i]]++;
    for (int i = 1; i < numsSize; i++) {
        if (arr[i] > 1) {
            return i;
        }
    }
    return 0;
}