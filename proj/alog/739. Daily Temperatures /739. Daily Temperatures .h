//
//  739. Daily Temperatures .h
//  leetcode
//
//  Created by andysheng on 2019/11/8.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _39__Daily_Temperatures__h
#define _39__Daily_Temperatures__h

namespace DailyTemperatures {
    class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& T) {
            vector<int> ret(T.size(), 0);
            for (int i = T.size() - 1; i > -1; --i) {
                int j = i + 1;
                while (j < T.size()) {
                    if (T[j] > T[i]) {
                        break;
                    } else if (ret[j] == 0) {
                        j = T.size();
                        break;
                    }  else if (T[i] == T[j]) {
                        j += ret[j];
                        break;
                    } else {
                        j += ret[j];
                    }
                }
                if (j < T.size()) {
                    ret[i] = j - i;
                }
            }

            return ret;
        }
    };
}
#endif /* _39__Daily_Temperatures__h */
