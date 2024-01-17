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

void deleter(int* arr, int* rezult_arr, int n) {
    rezult_arr[0] = arr[0];
    int iterator = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            rezult_arr[iterator] = arr[i];
            iterator += 1;
        }
    }
}

int main() {
    int n1;
    scanf("%d", &n1);
    int* arr1 = malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    int n2;
    scanf("%d", &n2);
    int* arr2 = malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    quicksort(arr1, 0, n1 - 1);
    quicksort(arr2, 0, n2 - 1);

    int len_of_help_arr1 = 1, len_of_help_arr2 = 1;
    for (int i = 1; i < n1; i++) {
        if (arr1[i] != arr1[i - 1]) {
            len_of_help_arr1 += 1;
        }
    }
    for (int i = 1; i < n2; i++) {
        if (arr2[i] != arr2[i - 1]) {
            len_of_help_arr2 += 1;
        }
    }
    int* help_arr1 = malloc(len_of_help_arr1 * sizeof(int));
    int* help_arr2 = malloc(len_of_help_arr2 * sizeof(int));

    deleter(arr1, help_arr1, n1);
    deleter(arr2, help_arr2, n2);

    int flag = 0;
    if (len_of_help_arr1 == len_of_help_arr2)
    {
        for (int i = 0; i < len_of_help_arr1; i++)
        {
            if (help_arr1[i] != help_arr2[i])
            {
                flag = 1;
                break;
            }
        }
    }
    else
    {
        flag = 1;
    }

    if (flag == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    free(arr1);
    free(arr2);
    free(help_arr1);
    free(help_arr2);

    return 0;
}

