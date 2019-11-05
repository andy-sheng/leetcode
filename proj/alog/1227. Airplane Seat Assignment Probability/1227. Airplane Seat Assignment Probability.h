//
//  1227. Airplane Seat Assignment Probability.h
//  leetcode
//
//  Created by andysheng on 2019/11/6.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _227__Airplane_Seat_Assignment_Probability_h
#define _227__Airplane_Seat_Assignment_Probability_h

namespace AirplaneSeatAssigmentProbaility {
    class Solution {
    public:
        double nthPersonGetsNthSeat(int n) {
            return (n == 1) ? 1 : 0.5;
        }
    };
}
#endif /* _227__Airplane_Seat_Assignment_Probability_h */
