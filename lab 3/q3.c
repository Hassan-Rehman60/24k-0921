#include <stdio.h>

int main() { float salary, taxRate, tax, netSalary;

// Input salary and tax rate printf("Enter your salary: "); scanf("%f", &salary);

printf("Enter the tax rate (in percentage): ");

scanf("%f", &taxRate);

// Calculate tax and net salary tax = (taxRate / 100) * salary, netSalary = salary - tax;

// Output the results printf("Tax to be paid: %.2f\n", tax); printf("Salary after tax: %.2f\n", netSalary);

return 0;

}