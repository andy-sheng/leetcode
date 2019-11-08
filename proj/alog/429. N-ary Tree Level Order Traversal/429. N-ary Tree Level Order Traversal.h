//
//  429. N-ary Tree Level Order Traversal.h
//  leetcode
//
//  Created by andysheng on 2019/11/7.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _29__N_ary_Tree_Level_Order_Traversal_h
#define _29__N_ary_Tree_Level_Order_Traversal_h

#include "DataStructures.h"

namespace N_aryTreeLevelOrderTraversal {
    class Solution {
    public:
        vector<vector<int>> levelOrder(Node* root) {
            vector<vector<int>> ret;
            
            if (!root) return ret;
            
            deque<Node *> que {root};
            int nodeInThisLevel = 1;
            int nodeInNextLevel = 0;
            while (!que.empty()) {
                vector<int> levelPrint;
                for (int i = 0; i < nodeInThisLevel; ++i) {
                    Node *node = que.front();
                    que.pop_front();
                    levelPrint.push_back(node->val);
                    for (Node *subNode : node->children) {
                        que.push_back(subNode);
                        ++nodeInNextLevel;
                    }
                }
                ret.push_back(levelPrint);
                nodeInThisLevel = nodeInNextLevel;
                nodeInNextLevel = 0;
            }
            
            return ret;
        }
    };
}

#endif /* _29__N_ary_Tree_Level_Order_Traversal_h */
