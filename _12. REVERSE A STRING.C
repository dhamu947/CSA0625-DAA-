#include <stdio.h>
#include <string.h>

// Function to print the reverse of a string
void reverseString(char str[]) {
    int length = strlen(str);

    // Swap characters from beginning and end
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    // Print the original string
    printf("Original string: %s\n", str);

    // Reverse the string
    reverseString(str);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
