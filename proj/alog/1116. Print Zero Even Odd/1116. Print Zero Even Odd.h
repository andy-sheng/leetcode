//
//  1116. Print Zero Even Odd.h
//  leetcode
//
//  Created by andysheng on 2020/1/1.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _116__Print_Zero_Even_Odd_h
#define _116__Print_Zero_Even_Odd_h

namespace P1116 {
    class ZeroEvenOdd {
    private:
        int n;
        int cur;
        std::mutex zeroLock;
        std::mutex oddLock;
        std::mutex evenLock;
    public:
        ZeroEvenOdd(int n) {
            this->n = n;
            oddLock.lock();
            evenLock.lock();
        }

        // printNumber(x) outputs "x", where x is an integer.
        void zero(function<void(int)> printNumber) {
            for (int i = 1; i <= n; ++i) {
                zeroLock.lock();
                printNumber(0);
                if (i % 2 == 1) {
                    oddLock.unlock();
                } else {
                    evenLock.unlock();
                }
            }
        }

        void even(function<void(int)> printNumber) {
            for (int i = 2; i <= n; i += 2) {
                evenLock.lock();
                printNumber(i);
                zeroLock.unlock();
            }
        }

        void odd(function<void(int)> printNumber) {
            for (int i = 1; i <= n; i += 2) {
                oddLock.lock();
                printNumber(i);
                zeroLock.unlock();
            }
        }
    };
}
#endif /* _116__Print_Zero_Even_Odd_h */
