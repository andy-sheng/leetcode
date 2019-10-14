//
//  1079. Letter Tile Possibilities.h
//  leetcode
//
//  Created by andysheng on 2019/10/14.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _079__Letter_Tile_Possibilities_h
#define _079__Letter_Tile_Possibilities_h

using namespace std;
namespace LetterTilePossibilities {
    inline int count(short charCnt[], int positionLeft) {
        if (positionLeft == 0) return 0;
        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            if (charCnt[i] > 0) {
                --charCnt[i];
                ++ret;
                ret += count(charCnt, positionLeft - 1);
                ++charCnt[i];
            }
        }
        return ret;
    }
    class Solution {
    public:
        int numTilePossibilities(string tiles) {
            short charCnt[26] = {0};
            for (int i = 0; i < tiles.size(); ++i) {
                ++charCnt[tiles[i] - 'A'];
            }
            
            return count(charCnt, tiles.size());
        }
    };
}
#endif /* _079__Letter_Tile_Possibilities_h */
