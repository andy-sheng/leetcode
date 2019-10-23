//
//  537. Complex Number Multiplication.h
//  leetcode
//
//  Created by andysheng on 2019/10/23.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _37__Complex_Number_Multiplication_h
#define _37__Complex_Number_Multiplication_h

using namespace std;
namespace ComplexNumberMultiplication {
    class Solution {
    public:
        string complexNumberMultiply(string a, string b) {
            pair<int, int> A = getab(a);
            pair<int, int> B = getab(b);
            
            string first = to_string(A.first * B.first - A.second * B.second);
            string second = to_string(A.first * B.second + A.second * B.first) ;
            
            return first + "+" + second + "i";
        }
        pair<int, int>getab(string complexNumber) {
            int i = 0;
            int a = 0;
            int positiveA = 1;
            int b = 0;
            int positiveB = 1;
            if (complexNumber[i] == '-') {
                positiveA = -1;
                ++i;
            }
        
            int weight = 1;
            while (complexNumber[i] != '+') {
                a = a * weight + (complexNumber[i] - '0');
                weight = 10;
                ++i;
            }
            ++i;
            if (complexNumber[i] == '-') {
                positiveB = -1;
                ++i;
            }
            weight = 1;
            while (complexNumber[i] != 'i') {
                b = b * weight + (complexNumber[i] - '0');
                weight = 10;
                ++i;
            }
            return make_pair(positiveA * a, positiveB * b);
        }
    };
}
#endif /* _37__Complex_Number_Multiplication_h */
