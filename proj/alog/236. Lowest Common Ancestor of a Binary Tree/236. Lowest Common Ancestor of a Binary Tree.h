//
//  236. Lowest Common Ancestor of a Binary Tree.h
//  leetcode
//
//  Created by andysheng on 2019/12/5.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _36__Lowest_Common_Ancestor_of_a_Binary_Tree_h
#define _36__Lowest_Common_Ancestor_of_a_Binary_Tree_h

#include "DataStructures.h"

namespace P236 {
    class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (!root || root == p || root == q) {
                return root;
            }
            
            TreeNode *left = lowestCommonAncestor(root->left, p, q);
            TreeNode *right = lowestCommonAncestor(root->right, p, q);
            
            if (left && right) {
                return root;
            } else if (left) {
                return left;
            } else if (right) {
                return right;
            } else {
                return NULL;
            }
        }
    };
}
#endif /* _36__Lowest_Common_Ancestor_of_a_Binary_Tree_h */
