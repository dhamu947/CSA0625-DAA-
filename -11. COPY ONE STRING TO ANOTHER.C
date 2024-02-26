#include <stdio.h>

// Function to copy one string to another
void stringCopy(char source[], char destination[]) {
    int i = 0;
    // Copy characters until null terminator is encountered
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    // Append null terminator to the destination string
    destination[i] = '\0';
}

int main() {
    char source[100], destination[100];

    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin);

    // Remove newline character if present
    if (source[strlen(source) - 1] == '\n') {
        source[strlen(source) - 1] = '\0';
    }

    // Copying source to destination
    stringCopy(source, destination);

    printf("Source string: %s\n", source);
    printf("Copied string: %s\n", destination);

    return 0;
}
