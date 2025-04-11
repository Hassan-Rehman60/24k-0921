#include <iostream>
using namespace std;

class Vector2D {
protected:
    double x, y;

public:
    Vector2D(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {}

    Vector2D operator+(Vector2D &other) {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(Vector2D &other) {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scale) {
        return Vector2D(x * scale, y * scale);
    }

    friend double computeDotProduct(Vector2D &v1, Vector2D &v2);

    friend ostream &operator<<(ostream &out, Vector2D &vec) {
        out << "(" << vec.x << ", " << vec.y << ")";
        return out;
    }
};

double computeDotProduct(Vector2D &v1, Vector2D &v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

int main() {
    Vector2D vecA(1, 2);
    Vector2D vecB(4, 5);

    Vector2D added = vecA + vecB;
    Vector2D subtracted = vecA - vecB;
    Vector2D scaled = vecA * 4.7;
    double dot = computeDotProduct(vecA, vecB);

    cout << "Vector A: " << vecA << endl;
    cout << "Vector B: " << vecB << endl;
    cout << "A + B = " << added << endl;
    cout << "A - B = " << subtracted << endl;
    cout << "A * 4.7 = " << scaled << endl;
    cout << "Dot Product = " << dot << endl;

    return 0;
}
