//
//  11. Container With Most Water.h
//  leetcode
//
//  Created by andysheng on 2021/9/12.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _1__Container_With_Most_Water_h
#define _1__Container_With_Most_Water_h

namespace P11 {

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ret = 0;
        while (i < j) {
            ret = max(ret, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return ret;
    }
};

}
#endif /* _1__Container_With_Most_Water_h */
