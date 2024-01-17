#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n;
    int arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int tmp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = tmp;
            j -= 1;
        }
        if (j != i) {
            for (int k = 0; k < n; ++k) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }
}