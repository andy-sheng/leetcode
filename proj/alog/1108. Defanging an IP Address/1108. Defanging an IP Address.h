//
//  1108. Defanging an IP Address.h
//  leetcode
//
//  Created by andysheng on 2019/9/30.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _108__Defanging_an_IP_Address_h
#define _108__Defanging_an_IP_Address_h

using namespace std;

namespace DefangingAnIPAddr {
    class Solution {
    public:
        string defangIPaddr(string address) {
            string ret(address.size() + 8, ' ');
            
            for (int i = 0, j = 0; i < address.size(); ++i) {
                if (address[i] >= '0' && address[i] <= '9') {
                    ret[j++] = address[i];
                } else {
                    ret[j++] = '[';
                    ret[j++] = '.';
                    ret[j++] = ']';
                }
            }
            
            return ret;
        }
    };
}
#endif /* _108__Defanging_an_IP_Address_h */
