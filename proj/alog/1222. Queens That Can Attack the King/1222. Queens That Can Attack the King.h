//
//  1222. Queens That Can Attack the King.h
//  leetcode
//
//  Created by andysheng on 2019/10/21.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _222__Queens_That_Can_Attack_the_King_h
#define _222__Queens_That_Can_Attack_the_King_h

#include <unordered_map>
#include <set>
#include <vector>
using namespace std;
namespace QueensThatCanAttackTheKing {
    class Solution {
    public:
        vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
            unordered_map<int, set<int>> map;
            for (vector<int> queen : queens) {
                if (map.find(queen[0]) == map.end()) {
                    map[queen[0]] = set<int> {queen[1]};
                } else {
                    map[queen[0]].insert(queen[1]);
                }
            }
            
            vector<vector<int>> ret;
            for (int row = king[0], col = king[1]; row > -1 && col > -1; --row, --col) {
                if (map.find(row) != map.end() && map[row].find(col) != map[row].end()) {
                    ret.push_back(vector<int>{row, col});
                    break;
                }
            }
            for (int row = king[0]; row > -1; --row) {
                int col = king[1];
                if (map.find(row) != map.end() && map[row].find(col) != map[row].end()) {
                    ret.push_back(vector<int>{row, col});
                    break;
                }
            }
            for (int row = king[0], col = king[1]; row > -1 && col < 8; --row, ++col) {
                if (map.find(row) != map.end() && map[row].find(col) != map[row].end()) {
                    ret.push_back(vector<int>{row, col});
                    break;
                }
            }
            for (int col = king[1]; col < 8; ++col) {
                int row = king[0];
                if (map.find(row) != map.end() && map[row].find(col) != map[row].end()) {
                    ret.push_back(vector<int>{row, col});
                    break;
                }
            }
            for (int row = king[0], col = king[1]; row < 8, col < 8; ++row, ++col) {
                if (map.find(row) != map.end() && map[row].find(col) != map[row].end()) {
                    ret.push_back(vector<int>{row, col});
                    break;
                }
            }
            for (int row = king[0]; row < 8; ++row) {
                int col = king[1];
                if (map.find(row) != map.end() && map[row].find(col) != map[row].end()) {
                    ret.push_back(vector<int>{row, col});
                    break;
                }
            }
            for (int row = king[0], col = king[1]; row < 8 && col > -1; ++row, --col) {
                if (map.find(row) != map.end() && map[row].find(col) != map[row].end()) {
                    ret.push_back(vector<int>{row, col});
                    break;
                }
            }
            for (int col = king[1]; col > -1; --col) {
                int row = king[0];
                if (map.find(row) != map.end() && map[row].find(col) != map[row].end()) {
                    ret.push_back(vector<int>{row, col});
                    break;
                }
            }
            
            return ret;
        }
    };
}
#endif /* _222__Queens_That_Can_Attack_the_King_h */
