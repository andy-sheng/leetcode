public class NumMatrix {
    private int[][] matrix;
    public NumMatrix(int[][] matrix) {
        if (matrix.length == 0) {
            this.matrix = new int[0][0];
            return;
        }
        this.matrix = new int[matrix.length][matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                this.matrix[i][j] = matrix[i][j];
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    this.matrix[i][j] += this.matrix[0][j - 1];
                } else if (j == 0) {
                    this.matrix[i][j] += this.matrix[i - 1][0];
                } else {
                    this.matrix[i][j] += this.matrix[i - 1][j] + this.matrix[i][j - 1] - this.matrix[i - 1][j - 1];
                }
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int result = this.matrix[row2][col2];
        if (row1 == 0 && col1 == 0) {
          return result;  
        }
        if (row1 ==0){
            result -= this.matrix[row2][col1 - 1];
        } else if (col1 == 0) {
            result -= this.matrix[row1 - 1][col2];
        } else {
            result -= this.matrix[row1 - 1][col2] + this.matrix[row2][col1 - 1] - this.matrix[row1 - 1][col1 - 1];
        }
        return result;
    }
}


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix = new NumMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);