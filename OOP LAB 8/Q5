#include <iostream>
using namespace std;

class Matrix2x2 {
private:
    int data[2][2];

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) {
        data[0][0] = a; data[0][1] = b;
        data[1][0] = c; data[1][1] = d;
    }

    Matrix2x2 operator+(const Matrix2x2& other) {
        return Matrix2x2(
            data[0][0] + other.data[0][0],
            data[0][1] + other.data[0][1],
            data[1][0] + other.data[1][0],
            data[1][1] + other.data[1][1]
        );
    }

    Matrix2x2 operator-(const Matrix2x2& other) {
        return Matrix2x2(
            data[0][0] - other.data[0][0],
            data[0][1] - other.data[0][1],
            data[1][0] - other.data[1][0],
            data[1][1] - other.data[1][1]
        );
    }

    Matrix2x2 operator*(const Matrix2x2& other) {
        return Matrix2x2(
            data[0][0] * other.data[0][0] + data[0][1] * other.data[1][0],
            data[0][0] * other.data[0][1] + data[0][1] * other.data[1][1],
            data[1][0] * other.data[0][0] + data[1][1] * other.data[1][0],
            data[1][0] * other.data[0][1] + data[1][1] * other.data[1][1]
        );
    }

    friend int getDeterminant(const Matrix2x2& m);
    friend class MatrixEditor;
    friend ostream& operator<<(ostream& out, const Matrix2x2& m);
};

int getDeterminant(const Matrix2x2& m) {
    return m.data[0][0] * m.data[1][1] - m.data[0][1] * m.data[1][0];
}

class MatrixEditor {
public:
    void setValue(Matrix2x2& m, int row, int col, int val) {
        m.data[row][col] = val;
    }
};

ostream& operator<<(ostream& out, const Matrix2x2& m) {
    out << m.data[0][0] << " " << m.data[0][1] << endl;
    out << m.data[1][0] << " " << m.data[1][1] << endl;
    return out;
}

int main() {
    Matrix2x2 A(1, 2, 3, 4);
    Matrix2x2 B(5, 6, 7, 8);
    MatrixEditor editor;

    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;

    cout << "A + B:\n" << A + B;
    cout << "A - B:\n" << A - B;
    cout << "A * B:\n" << A * B;

    cout << "Determinant of A: " << getDeterminant(A) << endl;

    editor.setValue(A, 0, 1, 10);
    cout << "Matrix A after modifying element (0,1):\n" << A;

    return 0;
}
