//
//  861. 861. Score After Flipping Matrix.h
//  leetcode
//
//  Created by andysheng on 2019/10/20.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _861__Score_After_Flipping_Matrix_h
#define _861__Score_After_Flipping_Matrix_h

#include <vector>


using namespace std;

namespace ScoreAfterFlippingMatrix {
    inline int myMax(int a, int b) {
        return a >= b ? a : b;
    }
    class Solution {
    public:
        int matrixScore(vector<vector<int>>& A) {
            int ret = 0;
            
            for (int row = 0; row < A.size(); ++row) {
                if (A[row][0] == 0) {
                    for (int col = 0; col < A[0].size(); ++col) {
                        A[row][col] = !A[row][col];
                    }
                }
            }
            
            for (int col = 0; col < A[0].size(); ++col) {
                int oneCnt = 0;
                for (int row = 0; row < A.size(); ++row) {
                    if (A[row][col]) {
                        ++oneCnt;
                    }
                }
                ret += myMax(oneCnt, A.size() - oneCnt) * (1 << (A[0].size() - col - 1));
            }
            
            return ret;
        }
    };
}
#endif /* _861__Score_After_Flipping_Matrix_h */
