//
//  1008. Construct Binary Search Tree from Preorder Traversal.h
//  leetcode
//
//  Created by andysheng on 2019/10/15.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _008__Construct_Binary_Search_Tree_from_Preorder_Traversal_h
#define _008__Construct_Binary_Search_Tree_from_Preorder_Traversal_h

#include "DataStructures.h"
#include <vector>
using namespace std;

namespace ConstructBinarySearchTreeFromPreorderTraversal {
    class Solution {
    public:
        TreeNode* bstFromPreorder(vector<int>& preorder) {
            return bstFromPreorder(preorder, 0, preorder.size() - 1);
        }

        TreeNode* bstFromPreorder(vector<int>& preorder, int begin, int end) {
            if (begin > end) return NULL;
            if (begin == end) return new TreeNode(preorder[begin]);

            TreeNode *root = new TreeNode(preorder[begin]);

            int sparatorIdx = begin + 1;
            for (int i = begin; i <= end && preorder[i] <= preorder[begin]; ++i) {
                sparatorIdx = i + 1;
            }

            root->left = bstFromPreorder(preorder, begin + 1, sparatorIdx - 1);
            root->right = bstFromPreorder(preorder, sparatorIdx, end);
            return root;
        }
    };
}

#endif /* _008__Construct_Binary_Search_Tree_from_Preorder_Traversal_h */
