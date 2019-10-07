//
//  686. Repeated String Match.h
//  leetcode
//
//  Created by andysheng on 2019/10/8.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _86__Repeated_String_Match_h
#define _86__Repeated_String_Match_h

using namespace std;
namespace RepeatedStringMatch {
    class Solution {
    private:
        void GetNext(string p,int next[])
        {
            int pLen = (int)p.size();
            next[0] = -1;
            int k = -1;
            int j = 0;
            while (j < pLen - 1)
            {
                if (k == -1 || p[j] == p[k])
                {
                    ++k;
                    ++j;
                    next[j] = k;
                }
                else
                {
                    k = next[k];
                }
            }
        }
        
        int KmpSearch(string s, string p)
        {
            int i = 0;
            int j = 0;
            int pLen = (int)p.size();
            int sLen = (int)s.size();
            int maxLen = (pLen - 1) * 2 + (pLen / sLen + 1) * sLen;
            int next[pLen];
            int times = 1;
            GetNext(p, next);
            while (i < maxLen && j < pLen)
            {
                times = (i + sLen) / sLen;
                if (j == -1 || s[i % sLen] == p[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    j = next[j];
                }
            }
            if (j == pLen)
                return times;
            else
                return -1;
        }
    public:
        int repeatedStringMatch(string A, string B) {
            return KmpSearch(A, B);
        }
    };
}

#endif /* _86__Repeated_String_Match_h */
