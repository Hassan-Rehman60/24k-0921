#include <stdio.h>

float calculate(float a, float b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0; // Avoid division by zero
        default: return 0;
    }
}

int main() {
    float num1, num2;
    char op;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Result: %.2f\n", calculate(num1, num2, op));
    return 0;
}