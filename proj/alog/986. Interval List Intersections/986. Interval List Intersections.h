//
//  986. Interval List Intersections.h
//  leetcode
//
//  Created by andysheng on 2019/10/28.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _86__Interval_List_Intersections_h
#define _86__Interval_List_Intersections_h

#include <vector>

using namespace std;

namespace IntervalListIntersections {
    class Solution {
    public:
        vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
            vector<vector<int>> ret;
            for (int i = 0, j = 0; i < A.size() && j < B.size();) {
                if ((A[i][0] >= B[j][0] && A[i][0] <= B[j][1])
                    || (B[j][0] >= A[i][0] && B[j][0] <= A[i][1])) {
                    ret.push_back(vector<int>{max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
                }
                int newI = i + (A[i][1] <= B[j][1]);
                int newJ = j + (A[i][1] >= B[j][1]);
                i = newI;
                j = newJ;
            }
            return ret;
        }
    };
}
#endif /* _86__Interval_List_Intersections_h */
