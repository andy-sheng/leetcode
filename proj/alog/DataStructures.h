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
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

#endif /* DataStructures_h */
