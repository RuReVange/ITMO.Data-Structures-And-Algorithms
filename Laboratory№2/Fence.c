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
    int nfriends;
    scanf("%d", &nfriends);

    int *NumberStartOfPlank = malloc(nfriends * sizeof(int));
    int* NumberEndOfPlank = malloc(nfriends * sizeof(int));
    for (int i = 0; i < nfriends; i++) {
        scanf("%d", &NumberStartOfPlank[i]);
        scanf("%d", &NumberEndOfPlank[i]);
    }

    quicksort(NumberStartOfPlank, 0, nfriends - 1);
    quicksort(NumberEndOfPlank, 0, nfriends - 1);

    int counter = 0;
    for (int i = 0; i < nfriends; ++i) {
        counter += NumberEndOfPlank[i] - NumberStartOfPlank[i] + 1;
        // количество покрашенных за одну проходку
        if (NumberEndOfPlank[i - 1] >= NumberStartOfPlank[i]) {
            counter -= NumberEndOfPlank[i - 1] - NumberStartOfPlank[i] + 1;
            // учитываем вариант вторичного окрашивания одной и той де доски
            // в этом случае от счетчика отнимаем дважды учтенные доски
        }

    }
    printf("%d", counter);
    free (NumberStartOfPlank);
    free (NumberEndOfPlank);
    return 0;
}

