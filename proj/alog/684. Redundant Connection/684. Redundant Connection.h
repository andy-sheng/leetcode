//
//  684. Redundant Connection.h
//  leetcode
//
//  Created by andysheng on 2019/12/30.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _84__Redundant_Connection_h
#define _84__Redundant_Connection_h

#include "DataStructures.h"

namespace P684 {
    class Solution {
    public:
        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            Algorithm::UnionFind unionFind(edges.size() + 1);
            int i = 0;
            for (; i < edges.size(); ++i) {
                if (unionFind.isConnected(edges[i][0], edges[i][1])) {
                    break;
                } else {
                    unionFind.Union(edges[i][0], edges[i][1]);
                }
            }
            return edges[i];
        }
    };
}
#endif /* _84__Redundant_Connection_h */
