//
//  814. Binary Tree Pruning.h
//  leetcode
//
//  Created by andysheng on 2019/10/17.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _14__Binary_Tree_Pruning_h
#define _14__Binary_Tree_Pruning_h

#include "DataStructures.h"

namespace BinaryTreePruning {
    class Solution {
    public:
        TreeNode* pruneTree(TreeNode* root) {
            if (hasOne(root)) {
                return root;
            } else {
                delete root;
                return NULL;
            }
        }
        bool hasOne(TreeNode* root) {
            if (!root) return false;
            
            bool leftChildHasOne = hasOne(root->left);
            if (!leftChildHasOne) {
                delete root->left;
                root->left = NULL;
            }
            
            bool rightChildHasOne = hasOne(root->right);
            if (!rightChildHasOne) {
                delete root->right;
                root->right = NULL;
            }
            
            return leftChildHasOne || rightChildHasOne || root->val > 0;
        }
    };
}
#endif /* _14__Binary_Tree_Pruning_h */
