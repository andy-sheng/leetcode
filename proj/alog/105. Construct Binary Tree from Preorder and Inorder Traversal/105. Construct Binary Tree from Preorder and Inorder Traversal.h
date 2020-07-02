//
//  105. Construct Binary Tree from Preorder and Inorder Traversal.h
//  leetcode
//
//  Created by andysheng on 2020/7/3.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _05__Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_h
#define _05__Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_h

#include "DataStructures.h"

namespace P105 {
    class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        }
        
        TreeNode* buildTree(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd) {
            if (pStart < pEnd) {
                int i = iStart;
                while (i < iEnd && inorder[i] != preorder[pStart]) { ++i; }
                
                TreeNode *root = new TreeNode(preorder[pStart]);
                root->left = buildTree(preorder, pStart + 1, pStart + 1 + i - iStart, inorder, iStart, i);
                root->right = buildTree(preorder, pStart + 1 + i - iStart, pEnd, inorder, i + 1, iEnd);
                return root;
            }
            return NULL;
        }
    };
}
#endif /* _05__Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_h */
