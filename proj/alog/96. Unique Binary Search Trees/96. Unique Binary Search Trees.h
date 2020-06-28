//
//  96. Unique Binary Search Trees.h
//  leetcode
//
//  Created by andysheng on 2020/6/29.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _6__Unique_Binary_Search_Trees_h
#define _6__Unique_Binary_Search_Trees_h

#include "DataStructures.h"

namespace P96 {
    class Solution {  
       public:
           vector<TreeNode*> generateTrees(int n) {
               if (n == 0) { return vector<TreeNode *>(); }
               vector<vector<vector<TreeNode *>>> cache(n + 1, vector<vector<TreeNode *>>(n + 1, vector<TreeNode *>(1, NULL)));
               vector<TreeNode*> ret;
               for (int nodeCnt = 1; nodeCnt <= n; ++nodeCnt) {
                   for (int startNode = 1; startNode + nodeCnt - 1 <= n; ++startNode) {
                       vector<TreeNode *> currentRet;
                       for (int rootNode = startNode; rootNode < startNode + nodeCnt; ++rootNode) {
                           vector<TreeNode *> leftTrees = cache[startNode][rootNode - 1];
                           vector<TreeNode *> rightTrees = rootNode + 1 <= n ? cache[rootNode + 1][startNode + nodeCnt - 1] : vector<TreeNode *>(1, NULL);
                           for (TreeNode *leftTree: leftTrees) {
                               for (TreeNode *rightTree: rightTrees) {
                                   TreeNode *root = new TreeNode(rootNode);
                                   root->left = leftTree;
                                   root->right = rightTree;
                                   currentRet.push_back(root);
                               }
                           }
                       }
                       if (currentRet.size() > 0) {
    
                           cache[startNode][startNode+nodeCnt-1] = currentRet;
                       }
                   }
               }
               return cache[1][n];
           }
       };
}
#endif /* _6__Unique_Binary_Search_Trees_h */
