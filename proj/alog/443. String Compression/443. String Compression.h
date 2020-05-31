//
//  443. String Compression.h
//  leetcode
//
//  Created by andysheng on 2020/5/31.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _43__String_Compression_h
#define _43__String_Compression_h

#import "DataStructures.h"

namespace P43 {
    class Solution {
    public:
        int compress(vector<char>& chars) {
            if (chars.size() == 0) { return 0; }
            int ret = 0;
            int charCnt = 0;
            int originSize = chars.size();
            for (int i = 0; i < originSize; ++i) {
                ++charCnt;
                if ((i + 1 < originSize && chars[i + 1] != chars[i]) || i + 1 >= originSize) {
                    chars.push_back(chars[i]);
                    if (charCnt == 1) {
                        ret += 1;
                    } else {
                        int num = 0;
                        vector<char>::iterator it = chars.end();
                        while (charCnt) {
                            chars.insert(it, charCnt % 10 + '0');
                            ++num;
                            charCnt = charCnt / 10;
                        }
                        ret += num + 1;
                    }
                    charCnt = 0;
                }
            }
            
            chars.erase(chars.begin(), chars.begin() + originSize);
            return chars.size();
        }
    };
}

#endif /* _43__String_Compression_h */
