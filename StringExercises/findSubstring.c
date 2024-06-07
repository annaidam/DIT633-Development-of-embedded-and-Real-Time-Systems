#include <stdio.h>

// Function to calculate the length of a string
int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to find a substring in a string
char* findSubstring(const char *mainStr, const char *subStr) {
    int mainLen = stringLength(mainStr);
    int subLen = stringLength(subStr);

    // If the substring is empty or longer than the main string, return NULL
    if (subLen == 0 || subLen > mainLen) {
        return NULL;
    }

    // Iterate through the main string
    for (int i = 0; i <= mainLen - subLen; i++) {
        // Check if the substring matches the portion of the main string
        int j;
        for (j = 0; j < subLen; j++) {
            if (mainStr[i + j] != subStr[j]) {
                break;
            }
        }
        // If we completed the loop, we found the substring
        if (j == subLen) {
            return (char *)&mainStr[i];
        }
    }

    // If no match is found, return NULL
    return NULL;
}

int main() {
    const char *mainStr = "Hello, this is a simple example.";
    const char *subStr = "simple";

    char *result = findSubstring(mainStr, subStr);

    if (result != NULL) {
        printf("Substring found at position: %ld\n", result - mainStr);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
