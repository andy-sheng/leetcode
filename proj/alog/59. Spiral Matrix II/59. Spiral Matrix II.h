//
//  59. Spiral Matrix II.h
//  leetcode
//
//  Created by andysheng on 2021/8/27.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _9__Spiral_Matrix_II_h
#define _9__Spiral_Matrix_II_h

namespace P59 {

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        pair<int, int> rowRange = make_pair(0, n - 1);
        pair<int, int> colRange = make_pair(0, n - 1);
        int direction = 0; // -1 valid 0 right 1 down 2 left 3 up
        pair<int, int> curPos = make_pair(0, 0);
        int idx = 1;
        do {
            ret[curPos.first][curPos.second] = idx++;
            if (direction == 0) {
                // go right
                if (curPos.second + 1 > colRange.second) {
                    // go down
                    direction = 1;
                    curPos.first += 1;
                    rowRange.first += 1;
                    if (curPos.first > rowRange.second) {
                        direction = -1;
                    }
                } else {
                    curPos.second += 1;
                }
            } else if (direction == 1) {
                // go down
                if (curPos.first + 1 > rowRange.second) {
                    // go left
                    direction = 2;
                    curPos.second -= 1;
                    colRange.second -= 1;
                    if (curPos.second < colRange.first) {
                        direction = -1;
                    }
                } else {
                    curPos.first += 1;
                }
            } else if (direction == 2) {
                // go left
                if (curPos.second - 1 < colRange.first) {
                    direction = 3;
                    curPos.first -= 1;
                    rowRange.second -= 1;
                    if (curPos.first < rowRange.first) {
                        direction = -1;
                    }
                } else {
                    curPos.second -= 1;
                }
            } else {
                // go up
                if (curPos.first - 1 < rowRange.first) {
                    // go right
                    direction = 0;
                    curPos.second += 1;
                    colRange.first += 1;
                    if (curPos.second > colRange.second) {
                        direction = -1;
                    }
                } else {
                    curPos.first -= 1;
                }
            }
        } while (direction != -1);
        return ret;
    }
};

}
#endif /* _9__Spiral_Matrix_II_h */
