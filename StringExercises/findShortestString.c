#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int shortestString() {
    char line[MAX_LINE_LENGTH];
    char shortestLine[MAX_LINE_LENGTH];
    int minLength = MAX_LINE_LENGTH;
    int currentLength = 0;

    // Initialize shortestLine with an empty string
    shortestLine[0] = '\0';

    printf("Enter strings and press Enter twice to stop\n");
    fflush(stdout);

    // Read lines until a blank line is encountered
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        // Check if the line is empty
        if (line[0] == '\n') {
            break;
        }

        // Remove the newline character if present
        line[strcspn(line, "\n")] = '\0';

        currentLength = strlen(line);

        // Update the minimum length and shortest line if the current line is shorter
        if (currentLength < minLength) {
            minLength = currentLength;
            strcpy(shortestLine, line);
        }
    }

    if (minLength == MAX_LINE_LENGTH) {
        printf("No input provided.\n");
    } else {
        printf("The shortest string is \"%s\" with %d characters.\n", shortestLine, minLength);
    }

    return 0;
}

int main() {
    shortestString();
    return 0;
}