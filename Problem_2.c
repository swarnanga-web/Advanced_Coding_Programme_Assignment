#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int cmp(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

int main() {
    int n;
    long long A[MAX], B[MAX], K;

    printf("Input N: ");
    scanf("%d", &n);

    printf("Input array: ");
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }

    printf("Input K: ");
    scanf("%lld", &K);

    int rem = A[0] % K;
    for (int i = 1; i < n; i++) {
        if (A[i] % K != rem) {
            printf("Output: -1\n");
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        B[i] = A[i] / K;
    }

    qsort(B, n, sizeof(long long), cmp);

    long long median = B[n / 2];

    long long operations = 0;
    for (int i = 0; i < n; i++) {
        operations += llabs(B[i] - median);
    }

    printf("Output: %lld\n", operations);

    return 0;
}