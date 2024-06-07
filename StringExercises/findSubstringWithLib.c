#include <stdio.h>
#include <string.h>

// Function to find a substring in a string
char* findSubstring(const char *mainStr, const char *subStr) {
    // Get the lengths of the main string and the substring
    int mainLen = strlen(mainStr);
    int subLen = strlen(subStr);

    // If the substring is empty or longer than the main string, return NULL
    if (subLen == 0 || subLen > mainLen) {
        return NULL;
    }

    // Iterate through the main string
    for (int i = 0; i <= mainLen - subLen; i++) {
        // Check if the substring matches the portion of the main string
        if (strncmp(&mainStr[i], subStr, subLen) == 0) {
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