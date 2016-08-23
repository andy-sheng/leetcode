bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int rows[9][9] = {{0,0}};
    int cols[9][9] = {{0,0}};
    int square[3][3][9] = {{0,0}};
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] != '.') {
                int num = board[i][j] - '1';
                if (rows[i][num] != 0) return false;
                rows[i][num]++;
                
                if (cols[j][num] != 0) return false;
                cols[j][num]++;
                
                if (square[i/3][j/3][num] != 0) return false;
                square[i/3][j/3][num]++;
            }
        }
    }
    return true;
}