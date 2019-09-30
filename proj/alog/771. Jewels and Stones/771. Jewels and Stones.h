//
//  771. Jewels and Stones.h
//  leetcode
//
//  Created by andysheng on 2019/10/1.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _71__Jewels_and_Stones_h
#define _71__Jewels_and_Stones_h

using namespace std;

namespace JewelsAndStones {
    class Solution {
    public:
        int numJewelsInStones(string J, string S) {
            bool dic[128] = {0};
            
            for (int i = 0; i < J.size(); ++i) {
                dic[J[i]] = true;
            }
            
            int ret = 0;
            for (int i = 0; i < S.size(); ++i) {
                if (dic[S[i]]) {
                    ++ret;
                }
            }
            
            return ret;
        }
    };
}

#endif /* _71__Jewels_and_Stones_h */
