//
//  106. Construct Binary Tree from Inorder and Postorder Traversal.h
//  leetcode
//
//  Created by andysheng on 2021/12/18.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _06__Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_h
#define _06__Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_h

#include "DataStructures.h"

namespace P106 {

class Solution {
private:
    vector<int> inorder;
    vector<int> postorder;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        return buildTree(0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* buildTree(int begin1, int end1, int begin2, int end2) {
        
        cout << begin2 << " - " << end2 << endl;
        if (end1 - begin1 < 0) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[end2]);
        int posInInorder = begin1;
        while (inorder[posInInorder] != postorder[end2]) ++posInInorder;
        cout << posInInorder << endl;
        int newBegin1 = begin1;
        int newEnd1 = posInInorder - 1;
        int newBegin2 = begin2;
        int newEnd2 = begin2 + newEnd1 - newBegin1;
        root->left = buildTree(newBegin1, newEnd1, newBegin2, newEnd2);
        newBegin1 = posInInorder + 1;
        newEnd1 = end1;
        newBegin2 = newEnd2 + 1;
        newEnd2 = end2 - 1;
        root->right = buildTree(newBegin1, newEnd1, newBegin2, newEnd2);
        return root;
    }
};

}
#endif /* _06__Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_h */
