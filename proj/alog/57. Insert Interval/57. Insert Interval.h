//
//  57. Insert Interval.h
//  leetcode
//
//  Created by andysheng on 2021/8/23.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _7__Insert_Interval_h
#define _7__Insert_Interval_h

namespace P57 {

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool inserted = false;
        vector<vector<int>> ret;
        for (int i = 0; i < intervals.size(); ++i) {
            vector<int> interval = intervals[i];
            if (!inserted && newInterval[0] <= interval[1]) {
                if (newInterval[0] >= interval[0] || newInterval[1] >= interval[0]) {
                    interval[0] = min(intervals[i][0], newInterval[0]);
                    interval[1] = max(intervals[i][1], newInterval[1]);
                } else {
                    ret.push_back(newInterval);
                }
                inserted = true;
            } else if (inserted) {
                if (ret.back()[1] >= interval[0]) {
                    ret[ret.size() - 1][1] = max(ret[ret.size() - 1][1], interval[1]);
                    continue;
                }
            }
            ret.push_back(interval);
        }
        if (!inserted) {
            ret.push_back(newInterval);
        }
        return ret;
    }
};

}
#endif /* _7__Insert_Interval_h */
