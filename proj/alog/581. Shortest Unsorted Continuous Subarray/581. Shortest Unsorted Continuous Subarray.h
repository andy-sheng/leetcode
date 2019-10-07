//
//  581. Shortest Unsorted Continuous Subarray.h
//  leetcode
//
//  Created by andysheng on 2019/10/7.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _81__Shortest_Unsorted_Continuous_Subarray_h
#define _81__Shortest_Unsorted_Continuous_Subarray_h

#include <vector>

using namespace std;

namespace ShortestUnsortedContinuousSubarray {
    class Solution {
    public:
        int findUnsortedSubarray(vector<int>& nums) {
            int ret = 0;
            
            int lowBoundary  = -1;
            int highBoundary = -2;
            
            // find left boundary
            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] > nums[i + 1]) {
                    int smallest = nums[i + 1];
                    for (int j = i + 1; j < nums.size(); ++j) {
                        smallest = smallest <= nums[j] ? smallest : nums[j];
                    }
                    for (int j = 0; j <= i; ++j) {
                        if (nums[j] > smallest) {
                            lowBoundary = j;
                            break;
                        }
                    }
                    break;
                }
            }
            
            // find right boundary
            for (int i = (int)nums.size() - 1; i > 0; --i) {
                if (nums[i] < nums[i - 1]) {
                    int biggest = nums[i - 1];
                    for (int j = i - 1; j >= lowBoundary; --j) {
                        biggest = biggest >= nums[j] ? biggest : nums[j];
                    }
                    for (int j = (int)nums.size() - 1; j >= i; --j) {
                        if (nums[j] < biggest) {
                            highBoundary = j;
                            break;
                        }
                    }
                    break;
                }
            }
            
            return highBoundary - lowBoundary + 1;
        }
    };
}

#endif /* _81__Shortest_Unsorted_Continuous_Subarray_h */
