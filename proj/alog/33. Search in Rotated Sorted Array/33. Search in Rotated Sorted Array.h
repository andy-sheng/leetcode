//
//  33. Search in Rotated Sorted Array.h
//  leetcode
//
//  Created by andysheng on 2021/7/28.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _3__Search_in_Rotated_Sorted_Array_h
#define _3__Search_in_Rotated_Sorted_Array_h

#include "DataStructures.h"

namespace P33 {

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
    
    int search(vector<int>& nums, int low, int upper, int target) {
        if (low > upper) { return -1; }
        int mid = (low + upper) / 2;
        if (nums[mid] == target) { return mid; }
        if ((nums[low] < nums[mid] && target >= nums[low] && target < nums[mid])
            || (nums[low] > nums[mid] && (target >= nums[low] || target < nums[mid]))) {
            return search(nums, low, mid - 1, target);
        }
        else if ((nums[mid] < nums[upper] && target > nums[mid] && target <= nums[upper])
                 || (nums[mid] > nums[upper] && (target > nums[mid] || target <= nums[upper]))) {
            return search(nums, mid + 1, upper, target);
        }

        return -1;
    }
    
};

}
#endif /* _3__Search_in_Rotated_Sorted_Array_h */
