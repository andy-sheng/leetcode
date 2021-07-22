//
//  1817. Finding the Users Active Minutes.h
//  leetcode
//
//  Created by andysheng on 2021/7/23.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _817__Finding_the_Users_Active_Minutes_h
#define _817__Finding_the_Users_Active_Minutes_h

#include "DataStructures.h"

namespace P1817 {

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ret(k, 0);
        unordered_map<int, unordered_set<int>> userTime;
        for (vector<int> log : logs) {
            if (userTime.find(log[0]) == userTime.end()) {
                userTime[log[0]] = unordered_set<int>();
            }
            userTime[log[0]].insert(log[1]);
        }
        for (unordered_map<int, unordered_set<int>>::iterator it = userTime.begin(); it != userTime.end(); ++it) {
            if (it->second.size() > 0)  {
                ret[it->second.size() - 1] += 1;
            }
        }
        return ret;
    }
};

}
#endif /* _817__Finding_the_Users_Active_Minutes_h */
