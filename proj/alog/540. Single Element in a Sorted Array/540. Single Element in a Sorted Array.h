//
//  540. Single Element in a Sorted Array.h
//  leetcode
//
//  Created by andysheng on 2019/11/29.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _40__Single_Element_in_a_Sorted_Array_h
#define _40__Single_Element_in_a_Sorted_Array_h

#include "DataStructures.h"

namespace P540 {
    class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            if (nums.size() == 1) return nums[0];
            return singleNonDuplicate(nums, 0, nums.size() - 1);
        }
        
        int singleNonDuplicate(vector<int>& nums, int from, int to) {
            int mid = (from + to)  / 2;
            if (to == from) {
                return nums[to];
            }
            if (to - from == 2) {
                if (nums[mid] == nums[mid + 1]) {
                    return nums[from];
                } else {
                    return nums[to];
                }
            }
            if ((to - mid) % 2 == 1) { // odd
                if (nums[mid] == nums[mid + 1]) {
                    to = mid - 1;
                } else {
                    from = mid + 1;
                }
            } else { // even
                if (nums[mid] == nums[mid + 1]) {
                    from = mid + 1;
                } else if (nums[mid] == nums[mid - 1]) {
                    to = mid - 2;
                } else {
                    return nums[mid];
                }
            }
            return singleNonDuplicate(nums, from, to);
        }
    };
}

#endif /* _40__Single_Element_in_a_Sorted_Array_h */
