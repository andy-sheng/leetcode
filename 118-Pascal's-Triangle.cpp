class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows >= 1) {
            vector<int> row;
            row.push_back(1);
            result.push_back(row);
        }
        if (numRows >= 2) {
            vector<int> row;
            row.push_back(1);
            row.push_back(1);
            result.push_back(row);
        }
        for (int i = 2; i < numRows; i++) {
            vector<int> row;
            row.push_back(1);
            for (int j = 0; j < i - 1; j++) {
                row.push_back(result[i-1][j] + result[i-1][j+1]);
            }
            row.push_back(1);
            result.push_back(row);
        }
        return result;
    }
};