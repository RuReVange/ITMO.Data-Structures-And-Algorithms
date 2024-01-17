#include <stdio.h>
#include <stdlib.h>

void quicksort(long int* arr, int left, int right) {

    if (left < right) {

        int it1 = left;
        int it2 = right;
        int middle = arr[(it1 + it2) / 2];

        while (it1 <= it2){

            while (arr[it1] < middle){
                it1 += 1;
            }
            while (arr[it2] > middle) {
                it2 -= 1;
            }

            if (it1 <= it2) {
                int tmp = arr[it1];
                arr[it1] = arr[it2];
                arr[it2] = tmp;
                it1 += 1;
                it2 -= 1;
            }
        }
        quicksort(arr, left, it2);
        quicksort(arr, it1, right);
    }
}

int optimal_sum(long int* arr, int n, int k, long int max_sum){
    long int sum = 0;
    int counter_of_k = 1;
    for (int i =0; i<n; i++){
        if (arr[i] > max_sum){
            return 0;
        }
        sum += arr[i];
        if (sum > max_sum){
            sum = arr[i];
            counter_of_k +=1;
        }
    }
    if (counter_of_k <= k){
        return 1;
    }
    return 0;
}

int main() {
    int n;
    int k;
    scanf("%d %d", &n, &k);

    long int arr[n];
    long int left = 1;
    long int right = 0;

    for (int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }
    for (int i = 0; i< n; i++) {
        right += arr[i];
    }
    while (left < right){
        long int mid = (left + right) / 2;
        if (optimal_sum(arr, n, k, mid)){
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    long int sum_of_partition = 0;
    int counter = 0;
    long int border[k-1];
    for (int i = 0; i<k-1; i++){
        border[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        sum_of_partition += arr[i];
        if (sum_of_partition > left) {
            border[counter] = i;
            sum_of_partition = arr[i];
            counter +=1;
        }
    }

    long int iter1 = 0;
    long int iter2 = k-2;
    long int position_of_division = 1;
    while (border[iter2] == 0 && position_of_division < n) {
        if (position_of_division != border[iter1]){
            border[iter2] = position_of_division;
            iter2 -= 1;
        }
        position_of_division +=1;
        if (position_of_division > border[iter1]){
            iter1+=1;
        }
    }

    quicksort(border, 0, k-2);

    for (int i = 0; i<k-1; i++){
        printf("%ld ", border[i]);
    }

    return 0;
}