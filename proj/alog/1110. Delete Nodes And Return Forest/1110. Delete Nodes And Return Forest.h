//
//  1110. Delete Nodes And Return Forest.h
//  leetcode
//
//  Created by andysheng on 2019/10/27.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _110__Delete_Nodes_And_Return_Forest_h
#define _110__Delete_Nodes_And_Return_Forest_h

#include <vector>
#include <unordered_set>
#include <deque>
#include "DataStructures.h"

using namespace std;

namespace DeleteNodesAndReturnForest {
    class Solution {
    public:
        vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
            unordered_set<int> deleteNums;
            for (int delNum : to_delete) {
                deleteNums.insert(delNum);
            }
            
            
            
            vector<TreeNode *> ret;
            deque<TreeNode *> que {root};
            if (deleteNums.find(root->val) == deleteNums.end()) {
                ret.push_back(root);
            }
            while (!que.empty()) {
                travel(NULL, que.front(), ret, que, deleteNums);
                que.pop_front();
            }
            
            return ret;
        }
        
        void travel(TreeNode *parent, TreeNode *root, vector<TreeNode *> &ret, deque<TreeNode *> &que, unordered_set<int> &to_delete) {
            if (!root) return;
            if (to_delete.find(root->val) != to_delete.end()) {
                if (parent && parent->left == root) {
                    parent->left = NULL;
                } else if (parent && parent->right == root) {
                    parent->right = NULL;
                }
                if (root->left) {
                    if (to_delete.find(root->left->val) == to_delete.end()) {
                        ret.push_back(root->left);
                    }
                    que.push_back(root->left);
                }
                if (root->right) {
                    if (to_delete.find(root->right->val) == to_delete.end()) {
                        ret.push_back(root->right);
                    }
                    que.push_back(root->right);
                }
            }
            else
            {
                travel(root, root->left, ret, que, to_delete);
                travel(root, root->right, ret, que, to_delete);
            }
            
        }
    };
}
#endif /* _110__Delete_Nodes_And_Return_Forest_h */
