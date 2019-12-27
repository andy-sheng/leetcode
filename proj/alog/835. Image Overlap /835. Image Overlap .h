//
//  835. Image Overlap .h
//  leetcode
//
//  Created by andysheng on 2019/12/28.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _35__Image_Overlap__h
#define _35__Image_Overlap__h

namespace P835 {
    class Solution {
    public:
        int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
            vector<pair<int, int>> ones;
            for (int i = 0; i < A.size(); ++i) {
                for (int j = 0; j < A[0].size(); ++j) {
                    if (A[i][j]) {
                        ones.push_back(make_pair(i, j));
                    }
                }
            }
            int ret = 0;
            int rowDelta = A.size() - 1; // -(n-1) ~ (n-1)
            int colDelta = A[0].size() - 1;
            for (int y = -rowDelta; y <= rowDelta; ++y) {
                for (int x = -colDelta; x <= colDelta; ++x) {
                    int tmp = 0;
                    for (auto pos : ones) {
                        int rowB = pos.first + y;
                        int colB = pos.second + x;
                        if (rowB >= 0
                            && rowB < B.size()
                            && colB >= 0
                            && colB < B[0].size()
                            && B[rowB][colB]
                            ) {
                            ++tmp;
                        }
                    }
                    ret = max(ret, tmp);
                }
            }
            return ret;
        }
    };
}
#endif /* _35__Image_Overlap__h */
