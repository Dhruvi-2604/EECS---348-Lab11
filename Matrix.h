#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Matrix {
private:
    int size;
    vector<vector<int>> data;

public:
    Matrix();
    Matrix(int n);

    void readFromFile(ifstream& file);
    void display() const;

    // Operator overloading
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    // Diagonal sums
    int sumMainDiagonal() const;
    int sumSecondaryDiagonal() const;

    // Row and column swaps (by value, so original not modified)
    void swapRows(int r1 = 0, int r2 = 1) const;
    void swapColumns(int c1 = 0, int c2 = 1) const;

    // Update a specific element
    void updateValue(int row = 0, int col = 0, int val = 100);

    // Getters
    int getSize() const { return size; }
    int getValue(int row, int col) const { return data[row][col]; }

    // Set value internally (for reading)
    void setValue(int row, int col, int val) { data[row][col] = val; }
};

#endif
