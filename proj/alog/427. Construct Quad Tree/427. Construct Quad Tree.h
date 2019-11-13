//
//  427. Construct Quad Tree.h
//  leetcode
//
//  Created by andysheng on 2019/11/14.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _27__Construct_Quad_Tree_h
#define _27__Construct_Quad_Tree_h

#include "DataStructures.h"

namespace ConstructQuadTree {
    class Node {
    public:
        bool val;
        bool isLeaf;
        Node* topLeft;
        Node* topRight;
        Node* bottomLeft;
        Node* bottomRight;

        Node() {}

        Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = _topLeft;
            topRight = _topRight;
            bottomLeft = _bottomLeft;
            bottomRight = _bottomRight;
        }
    };

    inline string makeKey(int row, int col, int r) {
        return to_string(row) + '_' + to_string(col) + '_' + to_string(r);
    }

    class Solution2 {
    public:
        Node* construct(vector<vector<int>>& grid) {
            unordered_map<string, int> sums;
            for (int row = 0; row < grid.size(); row += 1) {
                for (int col = 0; col < grid.size(); col += 1) {
                    sums[makeKey(row, col, 1)] = grid[row][col];
                }
            }
            for (int r = 2; r <= grid.size(); r = r << 1) {
                for (int row = 0; row < grid.size(); row += r) {
                    for (int col = 0; col < grid.size(); col += r) {
                        int formerR = r >> 1;
                        sums[makeKey(row, col, r)] = sums[makeKey(row, col, formerR)]
                            + sums[makeKey(row + formerR, col, formerR)]
                            + sums[makeKey(row, col + formerR, formerR)]
                            + sums[makeKey(row + formerR, col + formerR, formerR)];
                    }
                }
            }
//            for (unordered_map<string, int>::iterator it = sums.begin(); it != sums.end(); ++it) {
//                cout << it->first <<" " << it->second <<endl;
//            }
            return construct(grid, sums, 0, 0, grid.size());
        }
        
        Node* construct(vector<vector<int>>& grid, unordered_map<string, int> &sums, int row, int col, int r) {
            Node *root = NULL;
            string sumKey = makeKey(row, col, r);
            if (sums[sumKey] != 0 && sums[sumKey] != r * r) {
                int nextR = r >> 1;
                root = new Node(0,
                                false,
                                construct(grid, sums, row, col, nextR),
                                construct(grid, sums, row, col + nextR, nextR),
                                construct(grid, sums, row + nextR, col, nextR),
                                construct(grid, sums, row + nextR, col + nextR, nextR));
            } else {
//                cout << "left node row" << row << " col " << col << " r " << r << endl;
                root = new Node(sums[sumKey], true, NULL, NULL, NULL, NULL);
            }
            return root;
        }
        
    };



    class Solution {
    public:
        Node* construct(vector<vector<int>>& grid) {
            return construct(grid, 0, 0, grid.size());
        }
        
        Node* construct(vector<vector<int>>& grid, int row, int col, int r) {
            if (r == 1)
            {
                return new Node(grid[row][col], true, NULL, NULL, NULL, NULL);
            }
            int nextR = r >> 1;
            Node *topLeft = construct(grid, row, col, nextR);
            Node *topRight = construct(grid, row, col + nextR, nextR);
            Node *bottomLeft = construct(grid, row + nextR, col, nextR);
            Node *bottomRight = construct(grid, row + nextR, col + nextR, nextR);
                                          
            if (topLeft->isLeaf
                && topRight->isLeaf
                && bottomLeft->isLeaf
                && bottomRight->isLeaf
                && topLeft->val == topRight->val
                && topRight->val == bottomLeft->val
                && bottomLeft->val == bottomRight->val) {
                return new Node(bottomLeft->val, true, NULL, NULL, NULL, NULL);
            } else {
                return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
            }
        }
    };
}
#endif /* _27__Construct_Quad_Tree_h */
