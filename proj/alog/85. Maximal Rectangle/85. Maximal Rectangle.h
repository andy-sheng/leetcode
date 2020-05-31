//
//  85. Maximal Rectangle.h
//  leetcode
//
//  Created by andysheng on 2020/1/6.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _5__Maximal_Rectangle_h
#define _5__Maximal_Rectangle_h

namespace P85 {
    class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            int maxArea = 0;
            if (matrix.size() == 0) return 0;
            vector<int> dp(matrix[0].size(), 0);
            for (int row = 0; row < matrix.size(); ++row) {
                for (int col = 0; col < matrix[0].size(); ++col) {
                    dp[col] = matrix[row][col] == '1' ? dp[col] + 1 : 0;
                    cout << dp[col] << " ";
                }
                cout << endl;
                maxArea = max(maxArea, getMaxArea(dp));
            }
            return maxArea;
        }

        int getMaxArea(vector<int> heights) {
            int result=0;
            if(heights.empty())
                return result;
            stack<int> s;
            heights.push_back(0);
            for(int i=0; i<heights.size(); i++) {
                while(!s.empty() && heights[s.top()]>heights[i]) {
                    int t=s.top();
                    s.pop();
                    result=max(result,heights[t]*(s.empty()?i:(i-s.top()-1)));
                }
                s.push(i);
            }
            return result;
        }
    };
}
#endif /* _5__Maximal_Rectangle_h */
