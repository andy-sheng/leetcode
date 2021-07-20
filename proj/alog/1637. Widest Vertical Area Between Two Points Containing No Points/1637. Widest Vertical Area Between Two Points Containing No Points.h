//
//  1637. Widest Vertical Area Between Two Points Containing No Points.h
//  leetcode
//
//  Created by andysheng on 2021/7/21.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _637__Widest_Vertical_Area_Between_Two_Points_Containing_No_Points_h
#define _637__Widest_Vertical_Area_Between_Two_Points_Containing_No_Points_h

#include "DataStructures.h"

namespace P1637 {

using namespace std;

bool compare(vector<int> pointA, vector<int> pointB) {
    return pointA[0] < pointB[0];
}

class Solution {
public:
    
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ret = 0;
        sort(points.begin(), points.end(), compare);
        for (int i = 1; i < points.size(); ++i) {
            ret = MAX(ret, points[i][0] - points[i-1][0]);
        }
        return ret;
    }
//    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
//        if (points.size() < 2) return 0;
//        set<int> xs;
//        for (auto &p : points) xs.insert(p.front());
//        int res = 0, prev = *xs.begin();
//        for (auto it = xs.begin(); it != xs.end(); it++) {
//          res = max(res, *it - prev);
//          prev = *it;
//        }
//        return res;
//    }
};

}
#endif /* _637__Widest_Vertical_Area_Between_Two_Points_Containing_No_Points_h */
