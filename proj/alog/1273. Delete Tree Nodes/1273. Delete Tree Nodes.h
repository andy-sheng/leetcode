//
//  1273. Delete Tree Nodes.h
//  leetcode
//
//  Created by andysheng on 2019/12/1.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _273__Delete_Tree_Nodes_h
#define _273__Delete_Tree_Nodes_h

#include "DataStructures.h"

namespace P1273 {
    class Solution {
    public:
        int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
            for (int i  = value.size() - 1; i > 0; --i) {
                value[parent[i]] += value[i];
            }
            
            int ret = 0;
            if (value[0] != 0) {
                ret++;
            } else {
                return ret;
            }
            for (int i = 1; i < parent.size(); ++i) {
                if (value[i] != 0 && parent[parent[i]] != -2) {
                    ++ret;
                } else {
                    parent[i] = -2;
                }
            }
            return ret;
        }
    };
}
#endif /* _273__Delete_Tree_Nodes_h */
