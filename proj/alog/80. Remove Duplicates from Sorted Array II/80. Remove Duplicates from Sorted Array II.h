//
//  80. Remove Duplicates from Sorted Array II.h
//  leetcode
//
//  Created by andysheng on 2021/8/28.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _0__Remove_Duplicates_from_Sorted_Array_II_h
#define _0__Remove_Duplicates_from_Sorted_Array_II_h

namespace P80 {

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int forwardDelta = 0;
        int lastNum = -100000, lastNumCnt = 0;
        int numsCnt = nums.size();
        for (int i = 0; i < numsCnt; ++i) {
            if (nums[i] != lastNum) {
                lastNum = nums[i];
                lastNumCnt = 1;
                if (forwardDelta > 0) {
                    nums[i - forwardDelta] = nums[i];
                }
            } else {
                ++lastNumCnt;
                if (lastNumCnt > 2) {
                    ++forwardDelta;
                } else if (forwardDelta > 0) {
                    nums[i - forwardDelta] = nums[i];
                }
            }
        }

        return numsCnt - forwardDelta;
    }
};

}

#endif /* _0__Remove_Duplicates_from_Sorted_Array_II_h */
