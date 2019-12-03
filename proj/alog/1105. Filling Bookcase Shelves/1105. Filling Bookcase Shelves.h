//
//  1105. Filling Bookcase Shelves.h
//  leetcode
//
//  Created by andysheng on 2019/12/3.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _105__Filling_Bookcase_Shelves_h
#define _105__Filling_Bookcase_Shelves_h

#include "DataStructures.h"

namespace P1105 {
static int const kWidth = 0;
static int const kHeight = 1;
    class Solution {
    public:
        int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
            vector<int> dp(books.size(), 0);
            dp[0] = books.front()[1];
            for (int i = 1; i < books.size(); ++i) {
                int currentWidth = shelf_width - books[i][kWidth];
                int maxHeight = books[i][kHeight];
                dp[i] = dp[i - 1] + maxHeight;
                for (int j = i - 1; j > -1 && currentWidth > 0; --j) {
                    currentWidth -= books[j][kWidth];
                    if (currentWidth >= 0) {
                        maxHeight = max(books[j][kHeight], maxHeight);
                        dp[i] = min(dp[i], (j - 1 > -1 ? dp[j - 1] : 0) + maxHeight);
                    }
                }
            }
            return dp.back();
        }
    };
}
#endif /* _105__Filling_Bookcase_Shelves_h */
