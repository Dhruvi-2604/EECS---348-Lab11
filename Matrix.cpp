#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
using namespace std;

Matrix::Matrix() : size(0) {}
Matrix::Matrix(int n) : size(n), data(n, vector<int>(n, 0)) {}

void Matrix::readFromFile(ifstream& file) {
    file >> size;
    data.resize(size, vector<int>(size));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            file >> data[i][j];
}

void Matrix::display() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << setw(4) << data[i][j];
        cout << endl;
    }
    cout << endl;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (size != other.size) {
        cerr << "Matrix sizes do not match!" << endl;
        exit(1);
    }
    Matrix result(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result.setValue(i, j, data[i][j] + other.data[i][j]);
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (size != other.size) {
        cerr << "Matrix sizes do not match!" << endl;
        exit(1);
    }
    Matrix result(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            int sum = 0;
            for (int k = 0; k < size; k++)
                sum += data[i][k] * other.data[k][j];
            result.setValue(i, j, sum);
        }
    return result;
}

int Matrix::sumMainDiagonal() const {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += data[i][i];
    return sum;
}

int Matrix::sumSecondaryDiagonal() const {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += data[i][size - i - 1];
    return sum;
}

void Matrix::swapRows(int r1, int r2) const {
    if (r1 < 0 || r2 < 0 || r1 >= size || r2 >= size) {
        cerr << "Invalid row indices!" << endl;
        return;
    }
    Matrix temp = *this;
    std::swap(temp.data[r1], temp.data[r2]);
    cout << "After swapping rows " << r1 << " and " << r2 << ":\n";
    temp.display();
}

void Matrix::swapColumns(int c1, int c2) const {
    if (c1 < 0 || c2 < 0 || c1 >= size || c2 >= size) {
        cerr << "Invalid column indices!" << endl;
        return;
    }
    Matrix temp = *this;
    for (int i = 0; i < size; i++)
        std::swap(temp.data[i][c1], temp.data[i][c2]);
    cout << "After swapping columns " << c1 << " and " << c2 << ":\n";
    temp.display();
}

void Matrix::updateValue(int row, int col, int val) {
    if (row < 0 || col < 0 || row >= size || col >= size) {
        cerr << "Invalid indices!" << endl;
        return;
    }
    data[row][col] = val;
    cout << "After updating element (" << row << "," << col << ") = " << val << ":\n";
    display();
}
