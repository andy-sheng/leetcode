//
//  103. Binary Tree Zigzag Level Order Traversal.h
//  leetcode
//
//  Created by andysheng on 2020/7/2.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _03__Binary_Tree_Zigzag_Level_Order_Traversal_h
#define _03__Binary_Tree_Zigzag_Level_Order_Traversal_h

#include "DataStructures.h"

namespace P103 {
    class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> ret;
            if (!root) { return ret; }
            
            deque<TreeNode *> queue;
            int depth = 0;
            int curLevelCnt = 1;
            int nextLevelCnt = 0;
            queue.push_back(root);
            vector<int> curLevelItems(curLevelCnt, 0);
            while (!queue.empty()) {
                
                TreeNode *curNode = queue.front();
                queue.pop_front();
                --curLevelCnt;
                if (depth % 2 == 0) {
                    curLevelItems[curLevelItems.size() - curLevelCnt - 1] = curNode->val;
                } else {
                    curLevelItems[curLevelCnt] = curNode->val;
                }
                
                if (curNode->left) {
                    queue.push_back(curNode->left);
                    ++nextLevelCnt;
                }
                if (curNode->right) {
                    queue.push_back(curNode->right);
                    ++nextLevelCnt;
                }
                if (curLevelCnt == 0) {
                    ret.push_back(curLevelItems);
                    curLevelItems = vector<int>(nextLevelCnt, 0);
                    ++depth;
                    curLevelCnt = nextLevelCnt;
                    nextLevelCnt = 0;
                }
            }
            
            return ret;
        }
    };
}
#endif /* _03__Binary_Tree_Zigzag_Level_Order_Traversal_h */
