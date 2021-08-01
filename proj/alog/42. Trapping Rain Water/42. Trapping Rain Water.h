//
//  42. Trapping Rain Water.h
//  leetcode
//
//  Created by andysheng on 2021/8/1.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _2__Trapping_Rain_Water_h
#define _2__Trapping_Rain_Water_h

namespace P42 {

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        vector<int> leftMax(height.size(), height.front());
        vector<int> rightMax(height.size(), height.back());
        for (int i = 1; i < height.size(); ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        for (int i = height.size() - 2; i > -1; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        int ret = 0;
        for (int i = 1; i < height.size() - 1; ++i) {
            ret += max(min(leftMax[i], rightMax[i]) - height[i], 0);
        }
        return ret;
    }
};

}
#endif /* _2__Trapping_Rain_Water_h */
