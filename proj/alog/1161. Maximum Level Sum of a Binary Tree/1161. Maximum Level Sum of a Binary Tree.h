//
//  1161. Maximum Level Sum of a Binary Tree.h
//  leetcode
//
//  Created by andysheng on 2019/10/19.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _161__Maximum_Level_Sum_of_a_Binary_Tree_h
#define _161__Maximum_Level_Sum_of_a_Binary_Tree_h

#include <deque>
#include "DataStructures.h"
using namespace std;
namespace MaximumLevelSumOfABinaryTree {
    class Solution {
    public:
        int maxLevelSum(TreeNode* root) {
            if (!root) return 0;
            deque<TreeNode *> que;
            
            int level        = 1;
            int levelNodeCnt = 1;
            int nextLevelNodeCnt = 0;
            int levelSum     = 0;
            int maxLevelSum  = root->val;
            int maxLevel     = 1;
            
            que.push_back(root);
            
            while (!que.empty()) {
                TreeNode *node = que.front();
                que.pop_front();
                
                levelSum += node->val;
                
                if (node->left) {
                    que.push_back(node->left);
                    ++nextLevelNodeCnt;
                }
                
                if (node->right) {
                    que.push_back(node->right);
                    ++nextLevelNodeCnt;
                }
                
                --levelNodeCnt;
                
                if (levelNodeCnt == 0) {
                    if (levelSum > maxLevelSum) {
                        maxLevelSum = levelSum;
                        maxLevel = level;
                    }
                    ++level;
                    levelSum = 0;
                    levelNodeCnt = nextLevelNodeCnt;
                    nextLevelNodeCnt = 0;
                }
            }
            return maxLevel;
        }
        
        
    };
}
#endif /* _161__Maximum_Level_Sum_of_a_Binary_Tree_h */
