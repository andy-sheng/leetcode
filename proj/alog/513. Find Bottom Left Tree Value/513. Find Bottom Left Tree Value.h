//
//  513. Find Bottom Left Tree Value.h
//  leetcode
//
//  Created by andysheng on 2019/11/8.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _13__Find_Bottom_Left_Tree_Value_h
#define _13__Find_Bottom_Left_Tree_Value_h

#include "DataStructures.h"

namespace FindBottomLeftTreeValue {
    class Solution1 {
    public:
        int findBottomLeftValue(TreeNode* root) {
        
            int ret = 0;
            
            deque<TreeNode *> que {root};
            int nodeInThisLevel = 1;
            int nodeInNextLevel = 0;
            while (!que.empty()) {
                ret = que.front()->val;
                for (int i = 0; i < nodeInThisLevel; ++i) {
                    TreeNode *node = que.front();
                    que.pop_front();
                    
                    if (node->left)
                    {
                        que.push_back(node->left);
                        ++nodeInNextLevel;
                    }
                    
                    if (node->right)
                    {
                        que.push_back(node->right);
                        ++nodeInNextLevel;
                    }
                    
                }
                nodeInThisLevel = nodeInNextLevel;
                nodeInNextLevel = 0;
            }
            
            return ret;
        }
        
    };
    class Solution {
    public:
        int findBottomLeftValue(TreeNode* root) {
            int ret = 0;
            int maxDeep = 0;
            travel(root, 0, maxDeep, ret);
            return ret;
        }
        void travel(TreeNode *root, int deep, int &maxDeep, int &ret) {
            if (!root) return;
            ++deep;
            if (deep > maxDeep)
            {
                ret = root->val;
                maxDeep = deep;
            }
            travel(root->left, deep, maxDeep, ret);
            travel(root->right, deep, maxDeep, ret);
        }
    };
}
#endif /* _13__Find_Bottom_Left_Tree_Value_h */
