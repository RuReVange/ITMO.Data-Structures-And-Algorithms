#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++) {
        int k = i;
        while (k > 0 && arr[k - 1] > arr[k]) {
            int tmp = arr[k - 1];
            arr[k - 1] = arr[k];
            arr[k] = tmp;
            k -= 1;
        }

    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}