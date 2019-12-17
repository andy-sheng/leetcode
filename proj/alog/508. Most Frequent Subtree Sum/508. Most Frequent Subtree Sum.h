//
//  508. Most Frequent Subtree Sum.h
//  leetcode
//
//  Created by andysheng on 2019/12/18.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _08__Most_Frequent_Subtree_Sum_h
#define _08__Most_Frequent_Subtree_Sum_h

#include "DataStructures.h"

namespace P508 {
    class Solution {
    public:
        vector<int> findFrequentTreeSum(TreeNode* root) {
            unordered_map<int, int> sums;
            int sum = 0;
            travel(root, sums, sum);

            int maxFrequent = -1;
            for (pair<int, int> item : sums) {
                if (item.second > maxFrequent) {
                    maxFrequent = item.second;
                }
            }

            vector<int> ret;
            for (pair<int, int> item : sums) {
                if (item.second == maxFrequent) {
                    ret.push_back(item.first);
                }
            }
            return ret;
        }

        void travel(TreeNode* root, unordered_map<int, int> &sums, int &value) {
            if (!root) {
                value = 0;
                return;
            }
            int leftSubtreeSum = 0, rightSubtreeSum = 0;
            travel(root->left, sums, leftSubtreeSum);
            travel(root->right, sums, rightSubtreeSum);

            value = leftSubtreeSum + rightSubtreeSum + root->val;
            if (sums.find(value) == sums.end()) {
                sums[value] = 1;
            } else {
                ++sums[value];
            }
        }
    };
}
#endif /* _08__Most_Frequent_Subtree_Sum_h */
