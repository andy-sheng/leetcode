//
//  763. Partition Labels.h
//  leetcode
//
//  Created by andysheng on 2019/10/16.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _63__Partition_Labels_h
#define _63__Partition_Labels_h

#include <vector>

using namespace std;
namespace PartitionLabels {
    class Solution {
    public:
        vector<int> partitionLabels(string S) {
            int charFirstPositionArr[26];
            memset(charFirstPositionArr, -1, sizeof(int) * 26);
            for (int i = 0; i < S.size(); ++i) {
                short charValue = S[i] - 'a';
                if (charFirstPositionArr[charValue] == -1) {
                    charFirstPositionArr[charValue] = i;
                }
            }
            
            vector<int> ret;
            int parition = charFirstPositionArr[S.back() - 'a'];
            int lastParition = S.size();
            for (int i = S.size() - 1; i > -1; --i) {
                short charValue = S[i] - 'a';
                if (charFirstPositionArr[charValue] < parition) {
                    parition = charFirstPositionArr[charValue];
                } else if (parition == i) {
                    ret.insert(ret.begin(), lastParition - parition);
                    lastParition = parition;
                    --parition;
                }
            }
            
            return ret;
        }
    };
}

#endif /* _63__Partition_Labels_h */
