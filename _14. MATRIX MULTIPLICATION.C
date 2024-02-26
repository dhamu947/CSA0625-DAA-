#include <stdio.h>

#define N 2 // Size of matrices

// Function to add two matrices
void addMatrix(int A[][N], int B[][N], int C[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int A[][N], int B[][N], int C[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Strassen's algorithm for matrix multiplication
void strassenMultiply(int A[][N], int B[][N], int C[][N]) {
    if (N == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Dividing matrices into submatrices
    int A11[N/2][N/2], A12[N/2][N/2], A21[N/2][N/2], A22[N/2][N/2];
    int B11[N/2][N/2], B12[N/2][N/2], B21[N/2][N/2], B22[N/2][N/2];
    int C11[N/2][N/2], C12[N/2][N/2], C21[N/2][N/2], C22[N/2][N/2];
    int P1[N/2][N/2], P2[N/2][N/2], P3[N/2][N/2], P4[N/2][N/2], P5[N/2][N/2], P6[N/2][N/2], P7[N/2][N/2];
    int temp1[N/2][N/2], temp2[N/2][N/2];

    // Dividing A and B into submatrices
    for (int i = 0; i < N/2; i++) {
        for (int j = 0; j < N/2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + N/2];
            A21[i][j] = A[i + N/2][j];
            A22[i][j] = A[i + N/2][j + N/2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + N/2];
            B21[i][j] = B[i + N/2][j];
            B22[i][j] = B[i + N/2][j + N/2];
        }
    }

    // Calculating products P1 to P7
    addMatrix(A11, A22, temp1);
    addMatrix(B11, B22, temp2);
    strassenMultiply(temp1, temp2, P1); // P1 = (A11 + A22) * (B11 + B22)

    addMatrix(A21, A22, temp1);
    strassenMultiply(temp1, B11, P2); // P2 = (A21 + A22) * (B11)

    subtractMatrix(B12, B22, temp1);
    strassenMultiply(A11, temp1, P3); // P3 = (A11) * (B12 - B22)

    subtractMatrix(B21, B11, temp1);
    strassenMultiply(A22, temp1, P4); // P4 = (A22) * (B21 - B11)

    addMatrix(A11, A12, temp1);
    strassenMultiply(temp1, B22, P5); // P5 = (A11 + A12) * (B22)

    subtractMatrix(A21, A11, temp1);
    addMatrix(B11, B12, temp2);
    strassenMultiply(temp1, temp2, P6); // P6 = (A21 - A11) * (B11 + B12)

    subtractMatrix(A12, A22, temp1);
    addMatrix(B21, B22, temp2);
    strassenMultiply(temp1, temp2, P7); // P7 = (A12 - A22) * (B21 + B22)

    // Calculating C matrices
    addMatrix(P1, P4, temp1);
    subtractMatrix(temp1, P5, temp2);
    addMatrix(temp2, P7, C11); // C11 = P1 + P4 - P5 + P7

    addMatrix(P3, P5, C12); // C12 = P3 + P5

    addMatrix(P2, P4, C21); // C21 = P2 + P4

    addMatrix(P1, P3, temp1);
    subtractMatrix(temp1, P2, temp2);
    addMatrix(temp2, P6, C22); // C22 = P1 + P3 - P2 + P6

    // Combining C matrices into result matrix C
    for (int i = 0; i < N/2; i++) {
        for (int j = 0; j < N/2; j++) {
            C[i][j] = C11[i][j];
            C[i][j + N/2] = C12[i][j];
            C[i + N/2][j] = C21[i][j];
            C[i + N/2][j + N/2] = C22[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int mat[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[N][N] = {{1, 2}, {3, 4}};
    int B[N][N] = {{5, 6}, {7, 8}};
    int C[N][N];

    printf("Matrix A:\n");
    displayMatrix(A);

    printf("\nMatrix B:\n");
    displayMatrix(B);

    strassenMultiply(A, B, C);

    printf("\nResultant Matrix C:\n");
    displayMatrix(C);

    return 0;
}
