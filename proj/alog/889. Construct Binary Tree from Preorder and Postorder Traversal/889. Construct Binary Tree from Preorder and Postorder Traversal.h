//
//  889. Construct Binary Tree from Preorder and Postorder Traversal.h
//  leetcode
//
//  Created by andysheng on 2019/11/3.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _89__Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal_h
#define _89__Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal_h

#include "DataStructures.h"
#include <vector>
using namespace std;
namespace ConstructBinaryTreeFromPreorderAndPostorderTraversal {
    class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
            
            return constructFromPrePost(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
        }
        TreeNode* constructFromPrePost(vector<int>& pre, int preBegin, int preEnd,
                                       vector<int>& post, int postBegin, int postEnd) {
            if (preBegin == preEnd) {
                return new TreeNode(pre[preBegin]);
            }
            if (preBegin > preEnd) {
                return NULL;
            }
            TreeNode *root = new TreeNode(pre[preBegin]);
            int leftCnt = 1;
            if (preBegin + leftCnt <= preEnd) {
                while (pre[preBegin + 1] != post[postBegin + leftCnt - 1]) {
                    ++leftCnt;
                }
                root->left = constructFromPrePost(pre, preBegin + 1, preBegin + leftCnt,
                                                  post, postBegin, postBegin + leftCnt);
            }
            if (preBegin + leftCnt <= preEnd) {
                root->right = constructFromPrePost(pre, preBegin + leftCnt + 1, preEnd,
                                                   post, postBegin + leftCnt, postEnd - 1);
            }

            
            return root;
        }
    };
}
#endif /* _89__Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal_h */
