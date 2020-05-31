//
//  1002. Find Common Characters.h
//  leetcode
//
//  Created by andysheng on 2020/5/31.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _002__Find_Common_Characters_h
#define _002__Find_Common_Characters_h

#import "DataStructures.h"

namespace P1002 {

    class Solution {
    public:
        vector<string> commonChars(vector<string>& A) {
            vector<vector<short>> charCnts(A.size(), vector<short>(26, 0));
            for (int i = 0; i < A.size(); ++i) {
                for (char c: A[i]) {
                    ++charCnts[i][c - 'a'];
                }
            }
            
            vector<string> ret;
            for (int i = 0; i < 26; ++i) {
                int minCnt = charCnts[0][i];
                for (int j = 1; j < A.size() && minCnt > 0; ++j) {
                    minCnt = minCnt > charCnts[j][i] ? charCnts[j][i] : minCnt;
                }
                while (minCnt > 0) {
                    string tmp;
                    tmp.push_back(i+'a');
                    ret.push_back(tmp);
                    --minCnt;
                }
            }
            return ret;
        }
    };

}
#endif /* _002__Find_Common_Characters_h */
