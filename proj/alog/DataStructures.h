//
//  DataStructures.h
//  leetcode
//
//  Created by andysheng on 2019/9/30.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef DataStructures_h
#define DataStructures_h

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <deque>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

#endif /* DataStructures_h */
