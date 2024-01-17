#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void quicksort(int* arr, int firstindex, int lastindex)
{
    if (firstindex < lastindex)
    {
        int left = firstindex, right = lastindex, middle = arr[(left + right) / 2];
        do
        {
            while (arr[left] < middle) {
                left += 1;
            }
            while (arr[right] > middle) {
                right -= 1;
            }
            if (left <= right) {
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left += 1;
                right -= 1;
            }

        } while (left <= right);
        quicksort(arr, firstindex, right);
        quicksort(arr, left, lastindex);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}