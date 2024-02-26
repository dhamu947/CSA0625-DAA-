#include <stdio.h>
#include <string.h>

// Function to find the length of a string
int stringLength(char str[]) {
    int length = 0;

    // Iterate through the string until null terminator is encountered
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    int length = stringLength(str);

    printf("Length of the string: %d\n", length);

    return 0;
}

