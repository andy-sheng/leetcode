//
//  515. Find Largest Value in Each Tree Row.h
//  leetcode
//
//  Created by andysheng on 2019/11/17.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _15__Find_Largest_Value_in_Each_Tree_Row_h
#define _15__Find_Largest_Value_in_Each_Tree_Row_h

#include "DataStructures.h"

namespace FindLargestValueInEachTreeRow {
    class Solution {
    public:
        vector<int> largestValues(TreeNode* root) {
            vector<int> ret;
            
            if (!root) return ret;
            
            deque<TreeNode *> que {root};
            int nodeInThisLevel = 1;
            int nodeInNextLevel = 0;
            while (!que.empty()) {
                int maxVal = que.front()->val;
                for (int i = 0; i < nodeInThisLevel; ++i) {
                    TreeNode *node = que.front();
                    maxVal = max(maxVal, node->val);
                    que.pop_front();
                    if (node->left) {
                        que.push_back(node->left);
                        ++nodeInNextLevel;
                    }
                    if (node->right) {
                        que.push_back(node->right);
                        ++nodeInNextLevel;
                    }
                }
                ret.push_back(maxVal);
                nodeInThisLevel = nodeInNextLevel;
                nodeInNextLevel = 0;
            }
            
            return ret;
        }
    };
}
#endif /* _15__Find_Largest_Value_in_Each_Tree_Row_h */
