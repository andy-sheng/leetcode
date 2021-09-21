//
//  81. Search in Rotated Sorted Array II.h
//  leetcode
//
//  Created by andysheng on 2021/9/21.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _1__Search_in_Rotated_Sorted_Array_II_h
#define _1__Search_in_Rotated_Sorted_Array_II_h

namespace P81 {

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
    
    bool search(vector<int>& nums, int low, int high, int target) {
        // cout << low << " " << high << endl;
        if (low > high) { return false; }
        int mid = (low + high) / 2;
        if (nums[mid] == target) { return true; }
        
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            if (search(nums, low, mid - 1, target)) {
                return true;
            } else if (search(nums, mid + 1, high, target)) {
                return true;
            } else {
                return false;
            }
        } else if (nums[low] > nums[mid] && nums[mid] == nums[high]) {
            // low > mid == high
            return search(nums, low, mid - 1, target);
        } else if (nums[low] < nums[mid] && nums[mid] == nums[high]) {
            // low < mid == high
            if (target >= nums[low] && target < nums[mid]) {
                return search(nums, low, mid - 1, target);
            } else {
                return false;
            }
        } else if (nums[low] == nums[mid] && nums[mid] > nums[high]) {
            // low == mid > high
            return search(nums, mid + 1, high, target);
        } else if (nums[low] > nums[mid] && nums[mid] > nums[high]) {
            return false;
        } else if (nums[low] < nums[mid] && nums[mid] > nums[high]) {
            // low < mid > high
            if (target < nums[mid] && target >= nums[low]) {
                return search(nums, low, mid - 1, target);
            } else {
                return search(nums, mid + 1, high, target);
            }
        } else if (nums[low] == nums[mid] && nums[mid] < nums[high]) {
            // low == mid < high
            if (target <= nums[high]) {
                return search(nums, mid + 1, high, target);
            } else {
                return false;
            }
        } else if (nums[low] > nums[mid] && nums[mid] < nums[high]) {
            // low > mid < high
            if (target > nums[mid] && target <= nums[high]) {
                return search(nums, mid + 1, high, target);
            } else {
                return search(nums, low, mid - 1, target);
            }
        } else if (nums[low] < nums[mid] && nums[mid] < nums[high]) {
            // low < mid < high
            if (target > nums[mid] && target <= nums[high]) {
                return search(nums, mid + 1, high, target);
            } else {
                return search(nums, low, mid - 1, target);
            }
        }
        return false;
    }
};

}

#endif /* _1__Search_in_Rotated_Sorted_Array_II_h */
