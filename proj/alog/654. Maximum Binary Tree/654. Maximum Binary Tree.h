//
//  654. Maximum Binary Tree.h
//  leetcode
//
//  Created by andysheng on 2019/10/13.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _54__Maximum_Binary_Tree_h
#define _54__Maximum_Binary_Tree_h

#include <vector>
#include "DataStructures.h"

using namespace std;
namespace MaximumBinaryTree {
    class Solution {
    public:
        TreeNode* constructMaximumBinaryTree(vector<int>& nums, int begin, int end) {
            if (begin > end) return NULL;
            
            int maxPos = begin;
            for (int i = begin; i <= end; ++i) {
                if (nums[i] > nums[maxPos]) {
                    maxPos = i;
                }
            }
            TreeNode *leftTree = constructMaximumBinaryTree(nums, begin, maxPos - 1);
            TreeNode *root = new TreeNode(nums[maxPos]);
            TreeNode *rightTree = constructMaximumBinaryTree(nums, maxPos + 1, end);
            
            root->left = leftTree;
            root->right = rightTree;
            
            return root;
        }
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
        }
    };
}
#endif /* _54__Maximum_Binary_Tree_h */
