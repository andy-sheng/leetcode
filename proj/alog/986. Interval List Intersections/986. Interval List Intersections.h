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
                if (A[i][0] > B[j][1]) {
                    ++j;
                } else if (A[i][1] < B[j][0]) {
                    ++i;
                } else if (A[i][0] >= B[j][0] && A[i][0] <= B[j][1]) {
                    if (A[i][1] < B[j][1]) {
                        ret.push_back(vector<int> {A[i][0], A[i][1]});
                        ++i;
                    } else if (A[i][1] > B[j][1]) {
                        ret.push_back(vector<int> {A[i][0], B[j][1]});
                        ++j;
                    } else {
                        ret.push_back(vector<int> {A[i][0], A[i][1]});
                        ++i;
                        ++j;
                    }
                } else if (A[i][0] <= B[j][0] && A[i][1] >= B[j][0]) {
                    if (A[i][1] > B[j][1]) {
                        ret.push_back(vector<int> {B[j][0], B[j][1]});
                        ++j;
                    } else if (A[i][1] < B[j][1]) {
                        ret.push_back(vector<int> {B[j][0], A[i][1]});
                        ++i;
                    } else {
                        ret.push_back(vector<int> {B[j][0], B[j][1]});
                        ++i;
                        ++j;
                    }
                }
            }
            
            return ret;
        }
    };
}
#endif /* _86__Interval_List_Intersections_h */
