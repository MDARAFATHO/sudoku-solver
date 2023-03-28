#include <iostream>
using namespace std;

constexpr int GRID_SIZE = 9;
constexpr int VALUE_RANGE = 9;

int grid[GRID_SIZE][GRID_SIZE] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

bool isNumberInColumn(int column, int number) {
    for (auto& row : grid) {
        if (row[column] == number) {
            return true;
        }
    }
    return false;
}

bool isNumberInRow(int row, int number) {
    for (auto cell : grid[row]) {
        if (cell == number) {
            return true;
        }
    }
    return false;
}

bool isNumberInBox(int startRow, int startColumn, int number) {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (grid[startRow + row][startColumn + column] == number) {
                return true;
            }
         }
    }
    return false;
}

bool isValidPlacement(int row, int column, int number) {

    if (isNumberInRow(row, number) || isNumberInColumn(column, number)) {
        return false;
    }

int boxStartRow = row - row % 3;
int boxStartColumn = column - column % 3;

return !isNumberInBox(boxStartRow, boxStartColumn, number);

}

bool findEmptyCell(int& row, int& column) {
     for (row = 0; row < GRID_SIZE; row++) {
          for (column = 0; column < GRID_SIZE; column++) {
               if (grid[row][column] == 0) {
                   return true;
                }
            }
    }
    return false;
}

bool solveSudoku() {
int row, column;
    if (!findEmptyCell(row, column)) {

        return true;
    }

for (int number = 1; number <= VALUE_RANGE; number++) {
    if (isValidPlacement(row, column, number)) {
        grid[row][column] = number;

        if (solveSudoku()) {
            return true;
        }


        grid[row][column] = 0;
    }
}

  return false;
}

void printGrid() {
    for (auto& row : grid) {
         for (auto cell : row) {
              cout << cell << " ";
        }
    cout << endl;
    }
}

int main() {
if (solveSudoku()) {
    cout << "Solved sudoku:" << endl;
printGrid();
} else {
cout << "No solution found." << endl;
}
return 0;
}

