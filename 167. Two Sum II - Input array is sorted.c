/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i = 0, j = numbersSize - 1;
    *returnSize = 2;
    while(true) {
        while(numbers[j] > target - numbers[i]) j--;
        if (numbers[j] + numbers[i] < target) {
            i++;
        } else {
            int* result = malloc(2 * sizeof(int));
            result[0] = ++i;
            result[1] = ++j;
            return result;
        }
    }
}