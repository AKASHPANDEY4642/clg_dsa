#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void add(int* A, int sizeA, int* B, int sizeB, int* result);
void subtract(int* A, int sizeA, int* B, int sizeB, int* result);
void karatsubaMultiply(int* A, int sizeA, int* B, int sizeB, int* result);

// Helper functions
int max(int a, int b) {
    return (a > b) ? a : b;
}

void add(int* A, int sizeA, int* B, int sizeB, int* result) {
    int size = max(sizeA, sizeB);
    for (int i = 0; i < size; ++i) {
        result[i] = (i < sizeA ? A[i] : 0) + (i < sizeB ? B[i] : 0);
    }
}

void subtract(int* A, int sizeA, int* B, int sizeB, int* result) {
    int size = max(sizeA, sizeB);
    for (int i = 0; i < size; ++i) {
        result[i] = (i < sizeA ? A[i] : 0) - (i < sizeB ? B[i] : 0);
    }
}

void karatsubaMultiply(int* A, int sizeA, int* B, int sizeB, int* result) {
    int n = max(sizeA, sizeB);
    if (n == 0) return;
    if (n == 1) {
        result[0] = A[0] * B[0];
        return;
    }
    if (n % 2 != 0) n++;
    int m = n / 2;

    int* A0 = (int*)calloc(m, sizeof(int));
    int* A1 = (int*)calloc(m, sizeof(int));
    int* B0 = (int*)calloc(m, sizeof(int));
    int* B1 = (int*)calloc(m, sizeof(int));

    memcpy(A0, A, m * sizeof(int));
    memcpy(A1, A + m, (sizeA - m) * sizeof(int));
    memcpy(B0, B, m * sizeof(int));
    memcpy(B1, B + m, (sizeB - m) * sizeof(int));

    int* C0 = (int*)calloc(2 * m - 1, sizeof(int));
    int* C1 = (int*)calloc(2 * m - 1, sizeof(int));
    int* C2 = (int*)calloc(2 * m - 1, sizeof(int));
    int* temp1 = (int*)calloc(m, sizeof(int));
    int* temp2 = (int*)calloc(m, sizeof(int));

    karatsubaMultiply(A0, m, B0, m, C0);
    karatsubaMultiply(A1, m, B1, m, C1);
    add(A0, m, A1, m, temp1);
    add(B0, m, B1, m, temp2);
    karatsubaMultiply(temp1, m, temp2, m, C2);
    subtract(C2, 2 * m - 1, C0, 2 * m - 1, temp1);
    subtract(temp1, 2 * m - 1, C1, 2 * m - 1, C2);

    memset(result, 0, (2 * n - 1) * sizeof(int));
    for (int i = 0; i < 2 * m - 1; ++i) result[i] += C0[i];
    for (int i = 0; i < 2 * m - 1; ++i) result[i + m] += C2[i];
    for (int i = 0; i < 2 * m - 1; ++i) result[i + n] += C1[i];

    free(A0);
    free(A1);
    free(B0);
    free(B1);
    free(C0);
    free(C1);
    free(C2);
    free(temp1);
    free(temp2);
}

int main() {
    int degree1, degree2;
    scanf("%d", &degree1);
    int* poly1 = (int*)malloc((degree1 + 1) * sizeof(int));
    for (int i = degree1; i >= 0; --i) scanf("%d", &poly1[i]);

    scanf("%d", &degree2);
    int* poly2 = (int*)malloc((degree2 + 1) * sizeof(int));
    for (int i = degree2; i >= 0; --i) scanf("%d", &poly2[i]);

    int resultSize = 2 * max(degree1 + 1, degree2 + 1) - 1;
    int* result = (int*)calloc(resultSize, sizeof(int));

    karatsubaMultiply(poly1, degree1 + 1, poly2, degree2 + 1, result);

    for (int i = resultSize - 1; i >= 0; --i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(poly1);
    free(poly2);
    free(result);

    return 0;
}
