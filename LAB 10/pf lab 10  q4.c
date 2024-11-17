#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

float distance(Point a, Point b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int isWithinRectangle(Point p, Point bottomLeft, Point topRight) {
    return (p.x >= bottomLeft.x && p.x <= topRight.x && p.y >= bottomLeft.y && p.y <= topRight.y);
}

int main() {
    Point p1 = {1, 1}, p2 = {4, 5}, p = {3, 3}, bottomLeft = {0, 0}, topRight = {5, 5};

    printf("Distance between points: %.2f\n", distance(p1, p2));
    printf("Point is within rectangle: %s\n", isWithinRectangle(p, bottomLeft, topRight) ? "Yes" : "No");
    return 0;
}