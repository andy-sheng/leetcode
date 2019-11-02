//
//  969. Pancake Sorting.h
//  leetcode
//
//  Created by andysheng on 2019/11/3.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _69__Pancake_Sorting_h
#define _69__Pancake_Sorting_h
#include <vector>
#include <algorithm>
using namespace std;
namespace PanCakeSorting {
    class Solution {
    public:
        vector<int> pancakeSort(vector<int>& A) {
            vector<int> ret;
            for (int i = 0; i < A.size(); ++i) {
                int greatestPos = 0;
                for (int j  = 0; j < A.size() - i; ++j) {
                    if (A[j] > A[greatestPos]) {
                        greatestPos = j;
                    }
                }
                
                if (greatestPos == A.size() - 1 - i) {
                    continue;
                }
                
                if (greatestPos) {
                    ret.push_back(greatestPos + 1);
                }
                for (int j = 0; j <= greatestPos / 2; ++j) {
                    swap(A[j], A[greatestPos - j]);
                }
                
                ret.push_back(A.size() - i);
                for (int j = 0; j <= (A.size() - 1 - i) / 2; ++j) {
                    swap(A[j], A[A.size() - 1 - i - j]);
                }
            }
            return ret;
        }
    };
}
#endif /* _69__Pancake_Sorting_h */
