//
//  1305. All Elements in Two Binary Search Trees.h
//  leetcode
//
//  Created by andysheng on 2021/7/25.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _305__All_Elements_in_Two_Binary_Search_Trees_h
#define _305__All_Elements_in_Two_Binary_Search_Trees_h

#include "DataStructures.h"

namespace P1305 {

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1;
        preOrder(root1, arr1);
        vector<int> arr2;
        preOrder(root2, arr2);
        vector<int> ret(arr1.size() + arr2.size());
        int i = 0, j = 0, n = 0;
        while (i < arr1.size() && j < arr2.size()) {
            ret[n++] = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
        }
        while (i < arr1.size()) {
            ret[n++] = arr1[i++];
        }
        while (j < arr2.size()) {
            ret[n++] = arr2[j++];
        }
        return ret;
    }
    void preOrder(TreeNode* root, vector<int> &ret) {
        if (root) {
            preOrder(root->left, ret);
            ret.push_back(root->val);
            preOrder(root->right, ret);
        }
    }
};

}
#endif /* _305__All_Elements_in_Two_Binary_Search_Trees_h */
