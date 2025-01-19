#include <stdio.h>

// Function to add three numbers
void add_numbers(int *a, int *b, int *c, int *sum) {
    *sum = *a + *b + *c;
}

int main() {
    int num1 = 3, num2 = 5, num3 = 7, result;
    add_numbers(&num1, &num2, &num3, &result);
    printf("Sum: %d\n", result);
    return 0;
}

