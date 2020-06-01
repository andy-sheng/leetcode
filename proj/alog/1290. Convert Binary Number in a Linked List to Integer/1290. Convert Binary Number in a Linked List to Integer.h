//
//  Header.h
//  leetcode
//
//  Created by andysheng on 2020/6/1.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef Header_h
#define Header_h

namespace P1290 {
    class Solution {
    public:
        int getDecimalValue(ListNode* head) {
            int ret = 0;
            while (head) {
                ret = ret << 1;
                ret += head->val;
                head = head->next;
            }
            return ret;
        }
    };
}
#endif /* Header_h */
