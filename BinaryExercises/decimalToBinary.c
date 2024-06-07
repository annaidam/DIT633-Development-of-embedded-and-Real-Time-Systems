#include <stdio.h>

void decimalToBinary(int n) {
    printf("Your number %d in binary is ", n);
    
    if (n == 0) {
        printf("0");
        return;
    }

    int binary[32]; // assume 32-bit integers
    int i = 0;

    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    int input;
    printf("Enter the number you want to convert to binary: ");
    scanf("%d", &input);
    decimalToBinary(input);
    return 0;
}