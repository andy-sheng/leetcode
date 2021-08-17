//
//  93. Restore IP Addresses.h
//  leetcode
//
//  Created by andysheng on 2021/8/18.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _3__Restore_IP_Addresses_h
#define _3__Restore_IP_Addresses_h
#include "DataStructures.h"

namespace P93 {

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return restoreIpAddresses(s, 0, 4);
    }
    vector<string> restoreIpAddresses(string s, int pos, int level) {
        if (level > 1) {
            vector<string> posibilities;
            int val = 0;
            for (int i = 0; pos + i < s.size() && i < 3; ++i) {
                if (i == 0 && s[pos+i] == '0') {
                    posibilities.push_back("0");
                    break;
                }
                val = val * 10 + s[pos+i] - '0';
                if (val > 255) {
                    break;
                } else {
                    posibilities.push_back(s.substr(pos, i + 1));
                }
            }
            vector<string> ret;
            for (auto posibility: posibilities) {
                vector<string> subPosibilities = restoreIpAddresses(s, pos + posibility.size(), level - 1);
                for (auto subPosibility : subPosibilities) {
                    ret.push_back(posibility + "." + subPosibility);
                }
            }
            return ret;
        } else {
            string posibility = s.substr(pos, s.size() - pos);
            if (posibility.size() > 1 && posibility[0] == '0') {
                return {};
            } else if (posibility.size() > 3 || posibility.size() == 0) {
                return {};
            }
            int val = 0;
            for (auto c : posibility) {
                val = val * 10 + c - '0';
            }
            if (val > 255) {
                return {};
            } else {
                return {s.substr(pos, s.size() - pos)};
            }
        }
    }
};

}
#endif /* _3__Restore_IP_Addresses_h */
