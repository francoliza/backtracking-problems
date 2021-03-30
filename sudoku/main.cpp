#include<iostream>
#include<vector>

std::vector<std::vector<int> > grid = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                                        {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                                        {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                                        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                                        {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                                        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                                        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                                        {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                                        {0, 0, 5, 2, 0, 6, 3, 0, 0} };;


void printGrid(std::vector<std::vector<int> > grid) {
    for (int i = 0; i < 9; i++) {
        std::cout << " ";
        for (int j = 0; j < 9; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void sudokuSolver(std::vector<std::vector<int> > grid) {

}

int main() {
    printGrid(grid);
    return 0;
}