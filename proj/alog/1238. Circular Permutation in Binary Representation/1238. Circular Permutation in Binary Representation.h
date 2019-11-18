//
//  1238. Circular Permutation in Binary Representation.h
//  leetcode
//
//  Created by andysheng on 2019/11/19.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _238__Circular_Permutation_in_Binary_Representation_h
#define _238__Circular_Permutation_in_Binary_Representation_h
#include "DataStructures.h"
namespace CircularPermutationInBinaryRepresentation {
    class Solution {
    public:
        vector<int> circularPermutation(int n, int start) {
            if (n == 1) {
                return vector<int> {start, start xor 1};
            }
            vector<int> ret = circularPermutation(n - 1, start >> 1);
            for (int i = ret.size() - 1; i > -1; --i) {
                ret[i] = (ret[i] << 1) + (start & 1);
                ret.push_back(ret[i] xor 1);
            }
            return ret;
        }
     
    };
}
#endif /* _238__Circular_Permutation_in_Binary_Representation_h */
