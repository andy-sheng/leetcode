//
//  605. Can Place Flowers.h
//  leetcode
//
//  Created by andysheng on 2019/10/7.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _05__Can_Place_Flowers_h
#define _05__Can_Place_Flowers_h
#include <vector>

using namespace std;
namespace CanPlaceFlowers {
    class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            
            int placablePlotCnt = 0;
            
            int continuousStartIdx = -1;
            int continuousZeroCnt = 0;
            
            for (int i = 0; i < flowerbed.size(); ++i) {
                if (flowerbed[i] == 0) {
                    continuousStartIdx = continuousStartIdx < 0 ? i : continuousStartIdx;
                    ++continuousZeroCnt;
                } else {
                    if (continuousZeroCnt > 1) {
                        if (continuousStartIdx == 0) {
                            placablePlotCnt += continuousZeroCnt / 2;
                        } else {
                            placablePlotCnt += (continuousZeroCnt - 1) / 2;
                        }
                        
                    }
                    continuousStartIdx = -1;
                    continuousZeroCnt = 0;
                }
            }
            
            if (continuousZeroCnt > 0) {
                if (continuousStartIdx == 0) {
                    placablePlotCnt += (continuousZeroCnt + 1)  / 2;
                } else {
                    placablePlotCnt += continuousZeroCnt  / 2;
                }
                
            }
            
            return placablePlotCnt >= n;
        }
    };
}

#endif /* _05__Can_Place_Flowers_h */
