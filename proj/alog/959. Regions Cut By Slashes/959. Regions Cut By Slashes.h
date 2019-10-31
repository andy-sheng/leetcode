//
//  959. Regions Cut By Slashes.h
//  leetcode
//
//  Created by andysheng on 2019/10/31.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _59__Regions_Cut_By_Slashes_h
#define _59__Regions_Cut_By_Slashes_h

#include <vector>
using namespace std;

namespace RegionsCutBySlashes {
    class Solution {
    private:
        int rowCnt;
        int colCnt;
    public:
        int regionsBySlashes(vector<string>& grid) {
            int ret = 0;
            vector<int> tree(grid.size() * grid[0].size() * 5, -1);
            
            rowCnt = grid.size();
            colCnt = grid[0].size();
            
            for (int row = 0; row < rowCnt; ++row) {
                for (int col = 0; col < colCnt; ++col) {
                    if (grid[row][col] == ' ') {
                        union_(tree, getTopNode(tree, row, col), row * colCnt * 5  + col * 5);
                        union_(tree, getLeftNode(tree, row, col), row * colCnt * 5 + col * 5);
                    } else if (grid[row][col] == '\\') {
                        union_(tree, getTopNode(tree, row, col), row * colCnt * 5  + col * 5 + 2);
                        union_(tree, getLeftNode(tree, row, col), row * colCnt * 5  + col * 5 + 4);
                    } else if (grid[row][col] == '/') {
                        union_(tree, getTopNode(tree, row, col), row * colCnt * 5  + col * 5 + 1);
                        union_(tree, getLeftNode(tree, row, col), row * colCnt * 5  + col * 5 + 1);
                        tree[row * colCnt * 5  + col * 5 + 3] = row * colCnt * 5  + col * 5 + 3;
                    }
                }
            }
            
            for (int i = 0; i < tree.size(); ++i) {
                if (i == tree[i]) {
                    ++ret;
                }
            }
            
            for (int i : tree) {
                cout << i << endl;
            }
            
            return ret;
        }
        
        void union_(vector<int> &tree, int target, int newNode) {
            if (target == -1) {
                if (tree[newNode] == -1) {
                    tree[newNode] = newNode;
                }
                return;
            }
            while (tree[target] > -1 && tree[target] != target) {
                target = tree[target];
            }
            while (tree[newNode] > -1 && tree[newNode] != newNode) {
                newNode = tree[newNode];
            }
            tree[newNode] = target;
        }
        
        int getTopNode(vector<int> &tree, int row, int col) {
            if (row == 0) return -1;
            if (tree[(row - 1) * colCnt * 5  + col * 5] > -1) return (row - 1) * colCnt * 5  + col * 5;
            if (tree[(row - 1) * colCnt * 5  + col * 5 + 3] > -1) return (row - 1) * colCnt * 5  + col * 5 + 3;
            if (tree[(row - 1) * colCnt * 5  + col * 5 + 4] > -1) return (row - 1) * colCnt * 5  + col * 5 + 4;
            return -1;
        }
        int getLeftNode(vector<int> &tree, int row, int col) {
            if (col == 0) return -1;
            if (tree[row * colCnt * 5  + (col - 1) * 5] > -1) return row * colCnt * 5  + (col - 1) * 5;
            if (tree[row * colCnt * 5  + (col - 1) * 5 + 2] > -1) return row * colCnt * 5  + (col - 1) * 5 + 2;
            if (tree[row * colCnt * 5  + (col - 1) * 5 + 3] > -1) return row * colCnt * 5  + (col - 1) * 5 + 3;
            return -1;
        }
    };
}
#endif /* _59__Regions_Cut_By_Slashes_h */
