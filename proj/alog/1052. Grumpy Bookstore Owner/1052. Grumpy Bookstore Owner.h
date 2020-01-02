//
//  1052. Grumpy Bookstore Owner.h
//  leetcode
//
//  Created by andysheng on 2020/1/3.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _052__Grumpy_Bookstore_Owner_h
#define _052__Grumpy_Bookstore_Owner_h

#include "DataStructures.h"

namespace P1052 {
    class Solution {
    public:
        int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
            int total = 0;
            for (int i = 0; i < customers.size(); ++i) {
                if (!grumpy[i]) total += customers[i];
            }
            int maxCustomers = 0;
            int customersWhenGrumpy = 0;
            for (int i = 0; i < X; ++i) if (grumpy[i]) customersWhenGrumpy += customers[i];
            maxCustomers = customersWhenGrumpy;
            for (int i = X; i < customers.size(); ++i) {
                if (grumpy[i]) customersWhenGrumpy += customers[i];
                if (grumpy[i - X]) customersWhenGrumpy -= customers[i - X];
                maxCustomers = max(maxCustomers, customersWhenGrumpy);
            }
            
            return total + maxCustomers;
        }
        int maxSatisfied_dp(vector<int>& customers, vector<int>& grumpy, int X) {
            int noneGrumpCustomerCnt = 0;
            vector<int> dp(customers.size());
            for (int i = 0; i < X; ++i) {
                if (!grumpy[i]) noneGrumpCustomerCnt += customers[i];
                dp[i] = i == 0 ? customers[i] : dp[i - 1] + customers[i];
            }
            for (int i = X; i < customers.size(); ++i) {
                if (!grumpy[i]) noneGrumpCustomerCnt += customers[i];
                int customerCnt = 0;
                int noneGrumpCustomerCntBefore = noneGrumpCustomerCnt;
                int ret = 0;
                for (int j = i; j > i - X; --j) {
                    if (!grumpy[j]) noneGrumpCustomerCntBefore = noneGrumpCustomerCntBefore - customers[j];
                    customerCnt += customers[j];
                    ret = max(ret, noneGrumpCustomerCnt - noneGrumpCustomerCntBefore + dp[j - 1]);
                }
                ret = max(ret, noneGrumpCustomerCntBefore + customerCnt);
                dp[i] = ret;
            }
            return dp.back();
        }
    };
}
#endif /* _052__Grumpy_Bookstore_Owner_h */
