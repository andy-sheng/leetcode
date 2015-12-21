int maxSubArray(int* nums, int numsSize) {
    int max = nums[0], tMax = nums[0];
    int i = 0;
    while (i < numsSize && nums[i] < 0) { // find the first non-negative number
        if (nums[i] > max) {
            max = nums[i];
            tMax = max;
        }
        i++;
    }
    if (i == numsSize) { // all the numbers are negative
        return max;
    }
    // init
    max    = nums[i];
    tMax   = nums[i];
    while (i < numsSize) {
        while (i < numsSize && nums[i] < 0) { // find the first non-negative number
            i++;
        }
        if (i == numsSize) {
            break;
        }
        tMax = nums[i];
        int tValue = tMax;
        for (int forward = 1; i + forward < numsSize; forward++) {
            tValue += nums[i + forward];
            if (tValue < 0) { // stop forwarding
                i = i + forward;
                break;
            }
            if (tValue > tMax) {
                tMax = tValue;
            }
            
        }
        if (tMax > max) {
            max = tMax;
        }
        i++;
    }
    return max;
    
}