//
//  885. Spiral Matrix III.h
//  leetcode
//
//  Created by andysheng on 2019/10/23.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _85__Spiral_Matrix_III_h
#define _85__Spiral_Matrix_III_h

#include <vector>

using namespace std;
namespace SpiralMatrixIII {
    class Solution {
    public:
        vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
            bool topLeft = (r0 == 0 && c0 == 0);
            bool topRight = (r0 == 0 && c0 == C - 1);
            bool bottomLeft = (r0 == R - 1 && c0 == 0);
            bool bottomRight = (r0 == R - 1 && c0 == C - 1);
            vector<vector<int>> ret {{r0, c0}};
            for (int step = 1; !topLeft || !topRight || !bottomLeft || !bottomRight; step += 1) {
                for (int direction = 0; direction < 4; ++direction) {
                    int deltaR = 0;
                    int deltaC = 0;
                    if (direction == 0)
                    {
                        deltaR = 0;
                        deltaC = 1;
                    } else if (direction == 1) {
                        deltaR = 1;
                        deltaC = 0;
                    } else if (direction == 2) {
                        ++step;
                        deltaR = 0;
                        deltaC = -1;
                    } else if (direction == 3) {
                        deltaR = -1;
                        deltaC = 0;
                    }
                    for (int i = 1; i <= step; ++i) {
                        r0 += deltaR;
                        c0 += deltaC;
                        
                        cout << r0 << " " << c0 << endl;
                        if (r0 > -1 && r0 < R && c0 > -1 && c0 < C) {
                            ret.push_back(vector<int>{r0, c0});
                            topLeft = topLeft ?: (r0 == 0 && c0 == 0);
                            topRight = topRight ?: (r0 == 0 && c0 == C - 1);
                            bottomLeft = bottomLeft ?: (r0 == R - 1 && c0 == 0);
                            bottomRight = bottomRight ?: (r0 == R - 1 && c0 == C - 1);
                        }
                    }
                }
                if (topLeft && topRight && bottomLeft && bottomRight) {
                    break;
                }
            }
            return ret;
        }
    };
}
#endif /* _85__Spiral_Matrix_III_h */
