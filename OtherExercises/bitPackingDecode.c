#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

void hexToBin(char* hexdec, char* binaryNum);

#define SET_BIT(buffer, index) ((buffer)[(index) / 8 |= (1 << ((index) % 8))])
#define CLEAR_BIT(buffer, index) ((buffer)[(index) / 8 &= ~(1 << ((index) % 8)])
#define GET_BIT(bffer, index) (((buffer)[(index) / 8] >> ((index) % 8)) & 1)

int main(int argc, char* argv[]) {
    unsigned char* byte = malloc(1);
    int engine_on;
    int gear_pos;
    int key_pos;
    int brake1;
    int brake2;

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        printf("Usage: The program outputs the decoded information of given hexadecimal parameter");
        return 0;
    } else if (argc == 2) {
        char* hex = argv[1];
        char binaryNum[1000] = "0b";

        hexToBin(hex, binaryNum);

        if (binaryNum[3] == '1' && (binaryNum[4] == '1' || binaryNum[5] == '1')) {
            printf("Invalid input");
            return 2;
        } else if (binaryNum[6] == '1' && binaryNum[7] == '1') {
            printf("Invalid input");
            return 2;
        }

        // the 7th bit
        if (binaryNum[2] == '1') {
            engine_on = 1;
        } else {
            engine_on = 0;
        }

        // the 6th-4th bits
        int value = 0;
        if (binaryNum[3] == '1') {
            value += 4;
        } else if (binaryNum[4] == '1') {
            value += 2;
        } else if (binaryNum[5] == '1') {
            value += 1;
        }
        gear_pos = value;

        //the 3rd-2nd bits
        value = 0;
        if (binaryNum[6] == '1') {
            value += 2;
        } else if (binaryNum[7] == '1') {
            value += 2;
        }
        key_pos = value;

        // the 1st bit
        if (binaryNum[8] == '1') {
            brake1 = 1;
        } else {
            brake1 = 0;
        }

        // the 0th bit
        if (binaryNum[9] == '1') {
            brake2 = 1;
        } else {
            brake2 = 0;
        }
    } else {
        printf("Error with arguments");
        return 2;
    }

    printf("Name                Value\n");
    printf("-------------------------\n");
    printf("Engine on: %d\n", engine_on);
    printf("Gear position: %d\n", gear_pos);
    printf("Key position: %d\n", key_pos);
    printf("Brake 1: %d\n", brake1);
    printf("Brake 2: %d\n", brake2);
    return 0;
}

void hexToBin(char* hexdec, char* binaryNum) {
    size_t i = (hexdec[1] == 'x' || hexdec[1] == 'X') ? 2 : 0;
    while (hexdec[i]) {
        switch (hexdec[i]) {
            case '0':
                strcat(binaryNum, "0000");
                break;
            case '1':
                strcat(binaryNum, "0001");
                break;
            case '2':
                strcat(binaryNum, "0010");
                break;
            case '3':
                strcat(binaryNum, "0011");
                break;
            case '4':
                strcat(binaryNum, "0100");
                break;
            case '5':
                strcat(binaryNum, "0101");
                break;
            case '6':
                strcat(binaryNum, "0110");
                break;
            case '7':
                strcat(binaryNum, "0111");
                break;
            case '8':
                strcat(binaryNum, "1000");
                break;
            case '9':
                strcat(binaryNum, "1001");
                break;
            case 'A':
            case 'a':
                strcat(binaryNum, "1010");
                break;
            case 'B':
            case 'b':
                strcat(binaryNum, "1011");
                break;
            case 'C':
            case 'c':
                strcat(binaryNum, "1100");
                break;
            case 'D':
            case 'd':
                strcat(binaryNum, "1101");
                break;
            case 'E':
            case 'e':
                strcat(binaryNum, "1110");
                break;
            case 'F':
            case 'f':
                strcat(binaryNum, "1111");
                break;
            case '.':
                printf(".");
            default:
                printf("\nInvalid hexadecimal digit %c", hexdec[i]);
                return 2;
        }
        i++;
        if (i > 1) {
            printf("Hexadecimal is too long");
            return 2;
        }
    }
}