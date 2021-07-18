//
//  1689. Partitioning Into Minimum Number Of Deci-Binary Numbers.h
//  leetcode
//
//  Created by andysheng on 2021/7/19.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _689__Partitioning_Into_Minimum_Number_Of_Deci_Binary_Numbers_h
#define _689__Partitioning_Into_Minimum_Number_Of_Deci_Binary_Numbers_h

namespace P1689 {

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int ret = 0;
        for (int idx = 0; idx < n.size(); ++idx) {
            if (n[idx] - '0' < ret) { continue; }
            ret = n[idx] - '0';
        }
        return ret;
    }
    int minPartitions2(string n) {
        char ret = '0';
        for (int idx = 0; idx < n.size() && ret != '9'; ++idx) {
           ret = n[idx] > ret ? n[idx] : ret;
        }
        return ret - '0';
    }
};

}
#endif /* _689__Partitioning_Into_Minimum_Number_Of_Deci_Binary_Numbers_h */
