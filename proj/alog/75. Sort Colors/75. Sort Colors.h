//
//  75. Sort Colors.h
//  leetcode
//
//  Created by andysheng on 2021/8/27.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _5__Sort_Colors_h
#define _5__Sort_Colors_h

namespace P75 {

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redCnt = 0;
        int whiteCnt = 0;
        int blueCnt = 0;
        for (auto num: nums) {
            if (num == 0) {
                ++redCnt;
            } else if (num == 1) {
                ++whiteCnt;
            } else {
                ++blueCnt;
            }
        }
        int i = 0;
        for (; i < redCnt; ++i) nums[i] = 0;
        for (; i < redCnt + whiteCnt; ++i) nums[i] = 1;
        for (; i < redCnt + whiteCnt + blueCnt; ++i) nums[i] = 2;
    }
};

}
#endif /* _5__Sort_Colors_h */
