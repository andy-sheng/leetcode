//
//  1282. Group the People Given the Group Size They Belong To.h
//  leetcode
//
//  Created by andysheng on 2021/7/21.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _282__Group_the_People_Given_the_Group_Size_They_Belong_To_h
#define _282__Group_the_People_Given_the_Group_Size_They_Belong_To_h

#include <vector>


namespace P1282 {

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> map(501, vector<int>());
        vector<vector<int>> ret;
        for (int i = 0; i < groupSizes.size(); ++i) {
            int groupSize = groupSizes[i];
            map[groupSize].push_back(i);
            if (map[groupSize].size() == groupSize) {
                ret.push_back(map[groupSize]);
                map[groupSize] = vector<int>();
            }
        }
        return ret;
    }
};

}
#endif /* _282__Group_the_People_Given_the_Group_Size_They_Belong_To_h */
