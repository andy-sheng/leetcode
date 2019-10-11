//
//  1038. Binary Search Tree to Greater Sum Tree.h
//  leetcode
//
//  Created by andysheng on 2019/10/12.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _038__Binary_Search_Tree_to_Greater_Sum_Tree_h
#define _038__Binary_Search_Tree_to_Greater_Sum_Tree_h

#include "DataStructures.h"

namespace BinarySearchTreeToGreatSumTree {
    class Solution {
    private:
        void rebuildTree(TreeNode *searchTree, int &valueLeft) {
            if (!searchTree) return;
            
            rebuildTree(searchTree->right, valueLeft);
            
            valueLeft += searchTree->val;
            searchTree->val = valueLeft;
            
            rebuildTree(searchTree->left, valueLeft);
            
        }
    public:
        TreeNode* bstToGst(TreeNode* root) {
            int sum = 0;
            rebuildTree(root, sum);
            return root;
        }
    };
}

#endif /* _038__Binary_Search_Tree_to_Greater_Sum_Tree_h */
