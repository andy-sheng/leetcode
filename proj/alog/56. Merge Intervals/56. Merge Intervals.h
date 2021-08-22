//
//  56. Merge Intervals.h
//  leetcode
//
//  Created by andysheng on 2021/8/22.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _6__Merge_Intervals_h
#define _6__Merge_Intervals_h

#include "DataStructures.h"

namespace P56 {

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        ret.push_back(interval.front());
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> lastInterval = ret.back();
            vector<int> curInterval  = intervals[i];
            if (lastInterval[1] >= curInterval[0]) {
                ret[ret.size() - 1][1] = MAX(lastInterval[1], curInterval[1]);
            } else {
                ret.push_back(curInterval);
            }
        }
        return ret;
    }
};

}
#endif /* _6__Merge_Intervals_h */
