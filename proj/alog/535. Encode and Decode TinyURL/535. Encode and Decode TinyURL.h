//
//  535. Encode and Decode TinyURL.h
//  leetcode
//
//  Created by andysheng on 2019/10/13.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _35__Encode_and_Decode_TinyURL_h
#define _35__Encode_and_Decode_TinyURL_h

#include <unordered_map>
#include <vector>
using namespace std;
namespace EncodeAndDecodeTinyURL {
    class Solution {
    private:
        vector<string> storage;
        unordered_map<string, int> map;
    public:
        Solution() {
        }
        
        string transformInt2String(int intNum) {
            
            if (intNum == 0) return "0";
            
            string ret = "";
            while (intNum != 0) {
                int tmp = intNum % 62;
                if (tmp < 10) {
                    ret += tmp + '0';
                } else if (tmp < 36) {
                    ret += tmp - 10 + 'a';
                } else {
                    ret += tmp - 36 + 'A';
                }
                intNum /= 62;
            }
            return ret;
        }
        
        int transformString2Int(string strNum) {
            int ret = 0;
            int weight = 1;
            for (int i = 0; i < strNum.size(); ++i) {
                if (strNum[i] >= '0' && strNum[i] <= '9') {
                    ret += (strNum[i] - '0') * weight;
                } else if (strNum[i] >= 'a' && strNum[i] <= 'z') {
                    ret += (strNum[i] - 'a' + 10) * weight;
                } else {
                    ret += (strNum[i] - 'A' + 36) * weight;
                }
                weight *= 62;
            }
            return ret;
        }
        
        // Encodes a URL to a shortened URL.
        string encode(string longUrl) {
            int urlId = storage.size();
            if (map.find(longUrl) != map.end()) {
                urlId = map[longUrl];
            } else {
                storage.push_back(longUrl);
            }
            return transformInt2String(urlId);
        }

        // Decodes a shortened URL to its original URL.
        string decode(string shortUrl) {
            int urlId = transformString2Int(shortUrl);
            if (urlId < storage.size()) {
                return storage[urlId];
            } else {
                return "";
            }
        }
    };

    // https://leetcode.com/problems/design-tinyurl
    // http://tinyurl.com/4e9iAk
    // Your Solution object will be instantiated and called as such:
    // Solution solution;
    // solution.decode(solution.encode(url));
}
#endif /* _35__Encode_and_Decode_TinyURL_h */
