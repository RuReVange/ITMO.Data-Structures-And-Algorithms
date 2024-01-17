#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n;
    int number;
    int indexofnumber;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &number);
    scanf("%d", &indexofnumber);
    indexofnumber -= 1;
    for (int i = n-1; i >=indexofnumber; i--)
        arr[i+1] = arr[i];
    arr[indexofnumber] = number;
    for (int i = 0; i < n + 1; ++i) {
        printf("%d ", arr[i]);
    }
}