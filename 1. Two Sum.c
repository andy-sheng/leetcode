/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int hashMap[100000] = {0};
    int* result = malloc(2 * sizeof(int));
    for(int i = 0; i < numsSize; i++) {
        if (hashMap[target - nums[i] + 50000] == 0) {
            hashMap[nums[i] + 50000] = i + 1;
        } else {
            result[0] = hashMap[target - nums[i] + 50000] - 1;
            result[1] = i;
            break;
        }
    }
    return result;
}