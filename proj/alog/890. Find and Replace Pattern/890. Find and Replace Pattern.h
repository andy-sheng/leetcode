//
//  890. Find and Replace Pattern.h
//  leetcode
//
//  Created by andysheng on 2019/10/17.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _90__Find_and_Replace_Pattern_h
#define _90__Find_and_Replace_Pattern_h

#include <vector>

using namespace std;
namespace FindAndReplacePattern {
    class Solution {
    public:
        vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
            short pattern2source[26];
            short source2pattern[26];
            
            vector<string> ret;
            
            for (string word: words) {
                if (word.size() != pattern.size()) continue;
                memset(pattern2source, -1, sizeof(short) * 26);
                memset(source2pattern, -1, sizeof(short) * 26);
                int i;
                for (i = 0; i < word.size(); ++i) {
                    short sourceCharValue = word[i] - 'a';
                    short patterCharValue = pattern[i] - 'a';
                    if (pattern2source[patterCharValue] == -1 && source2pattern[sourceCharValue] == -1) {
                        pattern2source[patterCharValue] = sourceCharValue;
                        source2pattern[sourceCharValue] = patterCharValue;
                    } else {
                        if (pattern2source[patterCharValue] != sourceCharValue
                            || source2pattern[sourceCharValue] != patterCharValue) {
                            break;
                        }
                    }
                }
                if (i == word.size()) {
                    ret.push_back(word);
                }
            }
            return ret;
        }
    };
}

#endif /* _90__Find_and_Replace_Pattern_h */
