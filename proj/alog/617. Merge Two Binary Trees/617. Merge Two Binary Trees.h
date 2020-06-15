//
//  617. Merge Two Binary Trees.h
//  leetcode
//
//  Created by andysheng on 2020/6/15.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _17__Merge_Two_Binary_Trees_h
#define _17__Merge_Two_Binary_Trees_h

namespace P617 {
    class Solution {
    public:
        TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
            TreeNode *root = NULL;
            if (t1 && t2) {
                root = new TreeNode(t1->val + t2->val);
            } else if (t1) {
                root = new TreeNode(t1->val);
            } else if (t2) {
                root = new TreeNode(t2->val);
            } else {
                return root;
            }
            root->left = mergeTrees(!t1 ?: t1->left, !t2 ?: t2->left);
            root->right = mergeTrees(!t1 ?: t1->right, !t2 ?: t2->right);
            return root;
        }
    };
}
#endif /* _17__Merge_Two_Binary_Trees_h */
