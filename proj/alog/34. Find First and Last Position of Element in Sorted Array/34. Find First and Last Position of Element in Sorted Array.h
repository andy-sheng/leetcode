//
//  34. Find First and Last Position of Element in Sorted Array.h
//  leetcode
//
//  Created by andysheng on 2021/12/18.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _4__Find_First_and_Last_Position_of_Element_in_Sorted_Array_h
#define _4__Find_First_and_Last_Position_of_Element_in_Sorted_Array_h

#include "DataStructures.h"

namespace P34 {

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = search(nums, target);
        if (pos == -1) {
            return {-1, -1};
        }
        int low = searchLow(nums, 0, pos);
        int high = searchHigh(nums, pos, nums.size() - 1);
        return {low, high};
    }
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (high >= low) {
            int mid = (high + low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
    int searchLow(vector<int>& nums, int low, int high) {
        int target = nums[high];
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (nums[mid] != target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low] == nums[high] ? low : high;
    }
    int searchHigh(vector<int>& nums, int low, int high) {
        int target = nums[low];
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (nums[mid] != target) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        return nums[low] == nums[high] ? high : low;
    }
};

}
#endif /* _4__Find_First_and_Last_Position_of_Element_in_Sorted_Array_h */
