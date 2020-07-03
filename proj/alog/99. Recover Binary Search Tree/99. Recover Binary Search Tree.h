//
//  99. Recover Binary Search Tree.h
//  leetcode
//
//  Created by andysheng on 2020/7/4.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _9__Recover_Binary_Search_Tree_h
#define _9__Recover_Binary_Search_Tree_h
#include "DataStructures.h"
namespace P99 {
    class Solution {
    private:
        TreeNode *lastNode = NULL;
        TreeNode *errNode1 = NULL;
        TreeNode *errNode2 = NULL;
    public:
        void recoverTree(TreeNode* root) {
            findNode(root);
            int tmp = errNode2->val;
            errNode2->val = errNode1->val;
            errNode1->val = tmp;
        }
        void findNode(TreeNode* root) {
            if (!root) { return; }
            if (root->left) {
                findNode(root->left);
            }
            if (lastNode && root->val <= lastNode->val) {
                if (!errNode1) {
                    errNode1 = lastNode;
                    errNode2 = root;
                } else {
                    errNode2 = root;
                }
            }
            lastNode = root;
            findNode(root->right);
        }
    };
}
#endif /* _9__Recover_Binary_Search_Tree_h */
