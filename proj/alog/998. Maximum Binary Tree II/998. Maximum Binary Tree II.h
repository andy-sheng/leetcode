//
//  998. Maximum Binary Tree II.h
//  leetcode
//
//  Created by andysheng on 2019/11/6.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _98__Maximum_Binary_Tree_II_h
#define _98__Maximum_Binary_Tree_II_h

#include "DataStructures.h"

namespace MaximumBinaryTreeII {
    class Solution {
    public:
        TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
            if (val > root->val) {
                // must be left tree
                TreeNode *node = new TreeNode(val);
                node->left = root;
                return node;
            }
            travel(NULL, root, val);
            return root;
        }
        
        void travel(TreeNode *parent, TreeNode *root, int val) {
            if (!root || val > root->val) {
                TreeNode *node = new TreeNode(val);
                node->left = root;
                parent->right = node;
                return;
            }
            travel(root, root->right, val);
        }
    };
}
#endif /* _98__Maximum_Binary_Tree_II_h */
