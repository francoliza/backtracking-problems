#include<iostream>
#include<string>
#include<vector>

void printMatrix(std::vector<std::vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
       for (int j = 0; j < matrix.size(); j++) {
           std::cout << " " << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int isThreatened(std::vector<std::vector<int>> &matrix, int izq, int column) { // pregunta si la reina está amenazada
   if(izq == 0 && column == 0) {
       return 0;
   } else {
        int diagonal;
        for (int i = column - 1; i > -1; i--) {
            if (matrix[izq][i] == 1) {
                return 1;
            }
        }

       diagonal = izq + 1;
        //Up diagonal
        for (int i = column - 1; i > -1 && diagonal < matrix.size(); i--) {
            if (matrix[diagonal][i] == 1) {
                return 1;
            }
            diagonal++;
        }
        
        diagonal = izq - 1;
        //Down diagonal
        for (int i = column - 1; i > -1 && diagonal > -1; i--) {
            if (matrix[diagonal][i] == 1) {
                return 1;
            }
            diagonal--;
        }
   } 
   return 0;
}

int nqueens(std::vector<std::vector<int>> &matrix, int column, int n) {
    if (column == n) {
        return 1;
    }

   for (int i = 0; i < n; i++) {
        if (!isThreatened(matrix, i, column)) {
            matrix[i][column] = 1;
            if (nqueens(matrix, column + 1, n) == 1) {
                return 1;
            }
            matrix[i][column] = 0;
       }
   }
    
    return 0;
}

bool nqueens(std::vector<std::vector<int>> &matrix, int row, int column, int n) {
    
    if (column == n) 
        return true;

    if (row == n)
        return false;

    if (!isThreatened(matrix, row, column)) {
        matrix[row][column] = 1;
        if (nqueens(matrix, 0, column + 1, n)) 
            return 1;
        //BACKTRACK
        matrix[row][column] = 0;
    }

    return nqueens(matrix, row + 1, column, n);
}

int main(int argc, char** argv) {
   // terminé
    int n  = std::stoi(argv[1]);
    std::vector<std::vector<int>> matrix (n , std::vector<int> (n, 0));

    //nqueens(matrix, 0, n);
    nqueens(matrix, 0, 0, n);
    printMatrix(matrix);
    return 0;
}

