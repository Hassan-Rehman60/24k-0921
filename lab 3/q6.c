#include <stdio.h>

int main() {
    float x1 = 5, y1 = 4, x2 = 3, y2 = 2;
    float slope;

    // Calculate the slope
    slope = (y2 - y1) / (x2 - x1);
    
    // Output the slope with 3 decimal places
    printf("The slope is: %.3f\n", slope);
    
    return 0;
}