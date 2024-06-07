#include <stdio.h>
#include <stdlib.h>

void binaryCounter(unsigned int number) {
    int zeroCounter = 0;
    int oneCounter = 0;
    int leadingZerosSkipped = 0;
    int startedPrinting = 0;

    for (int i = 31; i >= 0; i--) {
        if ((number >> i) & 1) {
            if (!startedPrinting) {
                startedPrinting = 1;
            }
            oneCounter++;
            printf("%d", 1);
        } else {
            if (startedPrinting) {
                zeroCounter++;
                printf("%d", 0);
            } else {
                leadingZerosSkipped++;
            }
        }
    }

    if (!startedPrinting) {
        printf("0"); // For the case when the number is 0
    }

    printf("\nNumber of zeros: %d\n", zeroCounter);
    printf("Number of ones: %d\n", oneCounter);
}

int main() {
    unsigned int number = 6;
    binaryCounter(number);
    return 0;
}
