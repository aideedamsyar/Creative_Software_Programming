    #include "magic_square.h"

    void magic_square(int n, int **matrix) {
        int row = 0;
        int col = n / 2;

        for (int num = 1; num <= n * n; num++) {
            matrix[row][col] = num;

            int newRow = (row - 1 + n) % n;
            int newCol = (col + 1) % n;

            // Check if the next position is occupied
            if (matrix[newRow][newCol]) {
                row = (row + 1) % n;
            } else {
                row = newRow;
                col = newCol;
            }
        }
    }
