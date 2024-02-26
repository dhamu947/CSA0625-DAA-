#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check whether a character is a letter
bool isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Function to check whether a string is a palindrome
bool isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Skip non-letter characters
        while (!isLetter(str[left])) {
            left++;
        }
        while (!isLetter(str[right])) {
            right--;
        }
        // Convert characters to lowercase for case-insensitive comparison
        char leftChar = tolower(str[left]);
        char rightChar = tolower(str[right]);
        // If characters mismatch, string is not a palindrome
        if (leftChar != rightChar) {
            return false;
        }
        left++;
        right--;
    }
    // If control reaches here, string is a palindrome
    return true;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
