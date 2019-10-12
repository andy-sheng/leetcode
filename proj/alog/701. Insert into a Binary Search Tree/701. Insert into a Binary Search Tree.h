//
//  701. Insert into a Binary Search Tree.h
//  leetcode
//
//  Created by andysheng on 2019/10/13.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _01__Insert_into_a_Binary_Search_Tree_h
#define _01__Insert_into_a_Binary_Search_Tree_h

#include "DataStructures.h"

namespace InsertIntoABinarySearchTree {
    class Solution {
    public:
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            if (!root) return new TreeNode(val);
            if (val < root.val) {
                // insert into left tree
                if (!root->left) {
                    TreeNode *newNode = new TreeNode(val);
                    root->left = newNode;
                } else {
                    insertIntoBST(root->left, val);
                }
            } else {
                if (!root->right) {
                    TreeNode *newNode = new TreeNode(val);
                    root->right = newNode;
                } else {
                    insertIntoBST(root->right, val);
                }
            }
            return root;
        }
    };
}
#endif /* _01__Insert_into_a_Binary_Search_Tree_h */
