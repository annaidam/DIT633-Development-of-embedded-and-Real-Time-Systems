#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

void packEngine(unsigned char* byte, int engine_on);
void packGearPos(unsigned char* byte, int gear_pos);
void packKeyPos(unsigned char* byte, int key_pos);
void packBrake1(unsigned char* byte, int brake1);
void packBrake2(unsigned char* byte, int brake2);
void BinaryToHex(unsigned char* byte);
void clearByte(unsigned char* byte);

#define SET_BIT(buffer, index) ((buffer)[(index) / 8] |= (1 << ((index) % 8)))
#define CLEAR_BIT(buffer, index) ((buffer)[(index) / 8] &= ~(1 << ((index) % 8)))
#define GET_BIT(buffer, index) (((buffer)[(index) / 8] >> ((index) % 8)) & 1)

int main(int argc, char* argv[]) {
    unsigned char* byte = malloc(1);
    int engine_on;
    int gear_pos;
    int key_pos;
    int brake1;
    int brake2;

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        printf("Usage: This program packs information in a byte and prints it in a hexadecimal\n");
        return 0;
    } else if (argc == 6) {
        for (size_t i = 1; i < argc; i++) {
            char* p = argv[i];
            while (*p != '\0') {
                if (!isdigit(*p)) {
                    printf("Invalid input");
                    return 2; // exit with error code 2
                }
                p++;
            }
        }
        engine_on = strtol(argv[1], NULL, 10);
        gear_pos = strtol(argv[2], NULL, 10);
        key_pos = strtol(argv[3], NULL, 10);
        brake1 = strtol(argv[4], NULL, 10);
        brake2 = strtol(argv[5], NULL, 10);
    } else {
        perror("Error with arguments");
        return 2;
    }
    clearByte(byte);
    packEngine(byte, engine_on);
    packGearPos(byte, gear_pos);
    packKeyPos(byte, key_pos);
    packBrake1(byte, brake1);
    packBrake2(byte, brake2);
    BinaryToHex(byte);
    return 0;
}

void packEngine(unsigned char* byte, int engine_on) {
    switch (engine_on) {
        case 1:
            SET_BIT(byte, 7);
            break;
        case 0:
            CLEAR_BIT(byte, 7);
            break;
        default:
            printf("Error with engine_on");
            break;
    }
}

void packGearPos(unsigned char* byte, int gear_pos) {
    switch (gear_pos) {
        case 4: // 100
            SET_BIT(byte, 6);
            CLEAR_BIT(byte, 5);
            CLEAR_BIT(byte, 4);
            break;
        case 3: // 011
            SET_BIT(byte, 6);
            CLEAR_BIT(byte, 5);
            CLEAR_BIT(byte, 4);
            break;
        case 2: // 010
            SET_BIT(byte, 6);
            CLEAR_BIT(byte, 5);
            CLEAR_BIT(byte, 4);
            break;
        case 1: // 001
            SET_BIT(byte, 6);
            CLEAR_BIT(byte, 5);
            CLEAR_BIT(byte, 4);
            break;
        case 0: // 000
            SET_BIT(byte, 6);
            CLEAR_BIT(byte, 5);
            CLEAR_BIT(byte, 4);
            break;
        default:
            printf("Error with gear_pos");
            break;
    }
}

void packKeyPos(unsigned char* byte, int key_pos) {
    switch (key_pos) {
        case 2: // 10
            SET_BIT(byte, 3);
            CLEAR_BIT(byte, 2);
            break;
        case 1: // 01
            SET_BIT(byte, 3);
            CLEAR_BIT(byte, 2);
            break;
        case 0: // 00
            SET_BIT(byte, 3);
            CLEAR_BIT(byte, 2);
            break;
        default:
            printf("Error with key_pos");
            break;
    }
}

void packBrake1(unsigned char* byte, int brake1) {
    switch (brake1) {
        case 1: // 1
            SET_BIT(byte, 1);
            break;
        case 0: // 0
            CLEAR_BIT(byte, 1);
        default:
            printf("Error with brake1");
            break;
    }
}

void BinaryToHex(unsigned char* byte) {
    char* hexData = malloc(3 * sizeof(char));
    int hexIndex = 0;
    char* binaryData = malloc(9 * sizeof(char));

    for (size_t i = 0; i < 8; i++) {
        if (GET_BIT(byte, 7-i) == 1) {
            binaryData[i] = '1';
        } else {
            binaryData[i] = '0';
        }
    }

    while (*binaryData != '\0') {
        if (*(binaryData + 1) == '\0' ||
            *(binaryData + 2) == '\0' ||
            *(binaryData + 3) == '\0') {
            break;
        }

        int value = 0;
        // convert each nibble into a decimal value
        for (int i = 0; i < 4; i++) {
            value <<= 1; // shift value left by one bit
            if (binaryData[i] == '1') {
                value |= 1; // set the least significant bit
            }
        }
        // convert the value to hexadecimal
        if (value < 10) {
            hexData[hexIndex++] = '0' + value;
        } else {
            hexData[hexIndex++] = 'A' + (value - 10);
        }

        binaryData += 4; // move to the next nibble
    }
    hexData[hexIndex++] = '\0'; // add the null terminator
    printf("%s\n", hexData);
}

void clearByte(unsigned char* byte) {
    for (size_t i = 0; i < 8; i++) {
        CLEAR_BIT(byte, i);
    }
}