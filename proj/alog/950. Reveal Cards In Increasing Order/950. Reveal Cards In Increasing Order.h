//
//  950. Reveal Cards In Increasing Order.h
//  leetcode
//
//  Created by andysheng on 2019/10/15.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _50__Reveal_Cards_In_Increasing_Order_h
#define _50__Reveal_Cards_In_Increasing_Order_h

#include <algorithm>
#include <vector>
#include <deque>

/// deque 双端列表 支持快速随机访问。在头尾位置插入/删除速度很快。

using namespace std;
namespace RevealCardsInIncreasingOrder {
    class Solution {
    public:
        vector<int> deckRevealedIncreasing(vector<int>& deck) {
            deque<int> ret;

            sort(deck.begin(), deck.end());

            for (int i = deck.size() - 1; i > -1; --i) {

                if (ret.size() > 0) {
                    int tmp = ret.back();
                    ret.pop_back();
                    ret.push_front(tmp);
                }
                ret.push_front(deck[i]);
            }

            return vector<int> (ret.begin(), ret.end());
        }
    };
}

#endif /* _50__Reveal_Cards_In_Increasing_Order_h */
