vector<vector<int>> cache;
int size = 0;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int line = 0;
        
        if (numRows == 0) {
            vector<vector<int>> result;
            return result;
        }
        if (numRows > size) {
            line = size;
            size = numRows;
        } else {
            vector<vector<int>> result(&cache[0], &cache[numRows - 1]);
            return result;
        }
        
        
        
        if (numRows >= 1 && line < 1) {
            line++;
            vector<int> row;
            row.push_back(1);
            cache.push_back(row);
        }
        if (numRows >= 2 && line < 2) {
            line++;
            vector<int> row;
            row.push_back(1);
            row.push_back(1);
            cache.push_back(row);
        }
        
        for (; line < numRows; line++) {
            vector<int> row;
            row.push_back(1);
            int line_1 = line - 1;
            for (int j = 0; j < line_1;) {
                row.push_back(cache[line_1][j] + cache[line_1][++j]);
            }
            row.push_back(1);
            cache.push_back(row);
        }
        return cache;
    }
};