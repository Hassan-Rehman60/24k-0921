#include <iostream>
#include <sstream>
#include <exception>
using namespace std;

class DimensionMismatchError : public exception {
    string detail;
public:
    DimensionMismatchError(int r1, int c1, int r2, int c2) {
        ostringstream out;
        out << "DimensionMismatchError: Cannot add " << r1 << "x" << c1 << " with " << r2 << "x" << c2;
        detail = out.str();
    }

    const char* what() const noexcept override {
        return detail.c_str();
    }
};

template<typename T>
class Matrix {
    T** mat;
    int rowCount, colCount;

public:
    Matrix(int rows, int cols) : rowCount(rows), colCount(cols) {
        mat = new T*[rowCount];
        for (int i = 0; i < rowCount; ++i)
            mat[i] = new T[colCount];
    }

    ~Matrix() {
        for (int i = 0; i < rowCount; ++i)
            delete[] mat[i];
        delete[] mat;
    }

    void readValues() {
        cout << "Provide elements for a " << rowCount << "x" << colCount << " matrix:\n";
        for (int i = 0; i < rowCount; ++i)
            for (int j = 0; j < colCount; ++j)
                cin >> mat[i][j];
    }

    void display() const {
        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < colCount; ++j)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rowCount != other.rowCount || colCount != other.colCount)
            throw DimensionMismatchError(rowCount, colCount, other.rowCount, other.colCount);

        Matrix<T> sum(rowCount, colCount);
        for (int i = 0; i < rowCount; ++i)
            for (int j = 0; j < colCount; ++j)
                sum.mat[i][j] = mat[i][j] + other.mat[i][j];
        return sum;
    }
};

int main() {
    try {
        Matrix<int> a(2, 2);
        Matrix<int> b(2, 2);
        Matrix<int> c(3, 2);  

        cout << "Input for Matrix A:\n";
        a.readValues();

        cout << "Input for Matrix B:\n";
        b.readValues();

        Matrix<int> added = a + b;
        cout << "Sum of A and B:\n";
        added.display();

        Matrix<int> errorCase = a + c;
    } catch (const DimensionMismatchError& ex) {
        cout << "Caught exception: " << ex.what() << endl;
    }

    return 0;
}
