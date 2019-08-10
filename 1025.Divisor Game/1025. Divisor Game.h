//
//  1025. Divisor Game.h
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 盛旭辉. All rights reserved.
//

#ifndef _025__Divisor_Game_h
#define _025__Divisor_Game_h
#include <math.h>
namespace DivisorGame {
    class Solution {
    public:
        bool divisorGame(int N) {
            bool dp[N + 1];
            memset(dp, 0, sizeof(bool) * (N + 1));
            
            for (int i = 2; i <= N; ++i)
            {
                int limit = ceil(i / 2.0);
                bool ret = false;
                for (int j = 1; j <= limit; ++j)
                {
                    int k = i % j;
                    if (k == 0)
                    {
                        if (!dp[i - j])
                        {
                            ret = true;
                            break;
                        }
                    }
                }
                dp[i] = ret;
            }
            
            return dp[N];
        }
    };
}

#endif /* _025__Divisor_Game_h */
