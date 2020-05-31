//
//  1315. Sum of Nodes with Even-Valued Grandparent.h
//  leetcode
//
//  Created by andysheng on 2020/5/31.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _315__Sum_of_Nodes_with_Even_Valued_Grandparent_h
#define _315__Sum_of_Nodes_with_Even_Valued_Grandparent_h

#include "DataStructures.h"

namespace P1315 {
    class Solution {
    public:
        int sumEvenGrandparent(TreeNode* root) {
            vector<int> path;
            return doCalculation(root, path);
        }
        
        int doCalculation(TreeNode *root, vector<int> &path) {
            int val = 0;
            if (!root) { return val; }
            if (path.size() >= 2 && path[path.size() - 2] % 2 == 0) {
                val = root->val;
            }
            path.push_back(root->val);
            int sum = val + doCalculation(root->left, path) + doCalculation(root->right, path);
            path.pop_back();
            return sum;
        }
    };
}
#endif /* _315__Sum_of_Nodes_with_Even_Valued_Grandparent_h */
