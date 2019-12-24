//
//  919. Complete Binary Tree Inserter.h
//  leetcode
//
//  Created by andysheng on 2019/12/25.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _19__Complete_Binary_Tree_Inserter_h
#define _19__Complete_Binary_Tree_Inserter_h

#include "DataStructures.h"

namespace P919 {
    class CBTInserter {
    private:
        TreeNode *treeRoot;
        deque<TreeNode *> que;
    public:
        CBTInserter(TreeNode* root) {
            treeRoot = root;
            deque<TreeNode *> tmpQue{root};
            while (!tmpQue.empty()) {
                TreeNode *node = tmpQue.front();
                tmpQue.pop_front();
                if (!node->left || !node->right) {
                    que.push_back(node);
                }
                if (node->left) {
                    tmpQue.push_back(node->left);
                }
                if (node->right) {
                    tmpQue.push_back(node->right);
                }
            }
        }
        
        int insert(int v) {
            TreeNode *newNode = new TreeNode(v);
            que.push_back(newNode);
            TreeNode *node = que.front();
            if (!node->left) {
                node->left = newNode;
            } else {
                node->right = newNode;
                que.pop_front();
            }
            return node->val;
        }
        
        TreeNode* get_root() {
            return treeRoot;
        }
    };
}
#endif /* _9__Complete_Binary_Tree_Inserter_h */
