#include <stdio.h>

int main() {
    int n = 4; // Change this value to adjust the pattern size
    int i, j;

    // Outer loop for rows
    for (i = 1; i <= n; i++) {
        // Print spaces for the pyramid shape
        for (j = i; j < n; j++) {
            printf("  ");
        }
        // Print numbers
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
