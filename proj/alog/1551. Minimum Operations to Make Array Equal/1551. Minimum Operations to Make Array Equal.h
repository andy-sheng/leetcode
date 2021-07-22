//
//  1551. Minimum Operations to Make Array Equal.h
//  leetcode
//
//  Created by andysheng on 2021/7/23.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _551__Minimum_Operations_to_Make_Array_Equal_h
#define _551__Minimum_Operations_to_Make_Array_Equal_h

namespace P1551 {

class Solution {
public:
    int minOperations(int n) {
        int target = n;
        int ret = 0;
        int i = 0;
        int tmp = 1;
        while (tmp < n) {
            ret += n - tmp;
            tmp = ++i * 2 + 1;
        }
        return ret;
    }
};

}

#endif /* _551__Minimum_Operations_to_Make_Array_Equal_h */
