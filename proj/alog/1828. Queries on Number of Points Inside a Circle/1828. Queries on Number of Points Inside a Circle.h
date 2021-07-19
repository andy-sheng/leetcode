//
//  1828. Queries on Number of Points Inside a Circle.h
//  leetcode
//
//  Created by andysheng on 2021/7/20.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _828__Queries_on_Number_of_Points_Inside_a_Circle_h
#define _828__Queries_on_Number_of_Points_Inside_a_Circle_h

#include <vector>
#include <math.h>

namespace P1828 {

using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ret(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            vector<int> query = queries[i];
            int radiusSquare = query[2] * query[2];
            for (vector<int> point : points) {
                if ((pow((point[0] - query[0]), 2) + pow((point[1] - query[1]), 2)) <= radiusSquare) {
                    ++ret[i];
                }
            }
        }
        return ret;
    }
};

}

#endif /* _828__Queries_on_Number_of_Points_Inside_a_Circle_h */
