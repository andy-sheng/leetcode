//
//  49. Group Anagrams.h
//  leetcode
//
//  Created by andysheng on 2021/12/16.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _9__Group_Anagrams_h
#define _9__Group_Anagrams_h
#include "DataStructures.h"
namespace P49 {

class Solution {
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (auto str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            if (map.find(str) == map.end()) {
                map[str] = vector<string>();
            }
            map[key].push_back(str);
        }
        vector<vector<string>> ret;
        for (auto pair: map) {
            ret.push_back(pair.second);
        }
        return ret;
    }
};

}
#endif /* _9__Group_Anagrams_h */
