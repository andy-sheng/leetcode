//
//  1247. Minimum Swaps to Make Strings Equal.h
//  leetcode
//
//  Created by andysheng on 2019/12/1.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _247__Minimum_Swaps_to_Make_Strings_Equal_h
#define _247__Minimum_Swaps_to_Make_Strings_Equal_h

#include "DataStructures.h"

namespace P1247 {
    class Solution {
    public:
        int minimumSwap(string s1, string s2) {
            if (s1.size() != s2.size()) return -1;
            
            int xy = 0;
            int yx = 0;
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == 'x' && s2[i] == 'y') {
                    ++xy;
                } else if (s1[i] == 'y' && s2[i] == 'x') {
                    ++yx;
                }
            }
       
            if ((xy + yx) % 2) {
                return -1;
            } else {
                return xy / 2 + yx / 2 + ((yx % 2) ? 2 : 0);
            }
        }
    };
}
#endif /* _247__Minimum_Swaps_to_Make_Strings_Equal_h */
