#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Merge(int *arr, int left, int mid, int right)
{
    int leftiterator = 0;
    int rightiterator = 0;
    int* help_arr = malloc((right - left) * sizeof(int));
    while (left + leftiterator < mid && mid + rightiterator < right)
    {
        if (arr[left + leftiterator] < arr[mid + rightiterator])
        {
            help_arr[leftiterator + rightiterator] = arr[left + leftiterator];
            leftiterator+=1;
        }
        else
        {
            help_arr[leftiterator + rightiterator] = arr[mid + rightiterator];
            rightiterator+=1;
        }
    }
    while (leftiterator + left < mid)
    {
        help_arr[leftiterator + rightiterator] = arr[left + leftiterator];
        leftiterator+=1;
    }
    while (mid + rightiterator < right)
    {
        help_arr[leftiterator + rightiterator] = arr[mid + rightiterator];
        rightiterator+=1;
    }
    for (int start = 0; start < leftiterator + rightiterator; start++)
    {
        arr[left + start] = help_arr[start];
    }
    return;
}

void MergeSortRec(int* arr, int left, int right)
{
    if (left + 1 >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    MergeSortRec(arr, left, mid);
    MergeSortRec(arr, mid, right);
    Merge(arr, left, mid, right);
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    MergeSortRec(arr, 0, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}