#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i+1;
    }
    for (int i = 2; i < n; i++) {
        int tmp = arr[i];
        arr[i] = arr[i / 2];
        arr[i / 2] = tmp;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}