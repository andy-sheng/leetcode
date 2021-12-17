//
//  31. Next Permutation.h
//  leetcode
//
//  Created by andysheng on 2021/12/17.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _1__Next_Permutation_h
#define _1__Next_Permutation_h
#include "DataStructures.h"
namespace P31 {

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int carrySlot = -1;
        int size = nums.size();
        for (int i = size - 2; i > -1; --i) {
            if (nums[i] < nums[i+1]) {
                carrySlot = i;
                break;
            }
        }
        if (carrySlot != -1) {
            int exchangeSlot = carrySlot + 1;
            while (exchangeSlot < size && nums[exchangeSlot] > nums[carrySlot]) ++exchangeSlot;
            swap(nums[carrySlot], nums[exchangeSlot-1]);
        }
        reverse(nums.begin()+carrySlot+1, nums.end());
    }
};

}
#endif /* _1__Next_Permutation_h */
