#include "Matrix.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filename;
    cout << "Enter the input filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Cannot open file." << endl;
        return 1;
    }

    Matrix A, B;
    A.readFromFile(file);
    B.readFromFile(file);

    cout << "Matrix A:\n";
    A.display();

    cout << "Matrix B:\n";
    B.display();

    cout << "A + B:\n";
    (A + B).display();

    cout << "A * B:\n";
    (A * B).display();

    cout << "Sum of main diagonal of A: " << A.sumMainDiagonal() << endl;
    cout << "Sum of secondary diagonal of A: " << A.sumSecondaryDiagonal() << endl;

    A.swapRows(); // default rows 0 and 1
    A.swapColumns(); // default columns 0 and 1

    A.updateValue(); // default (0,0)=100

    file.close();
    return 0;
}
