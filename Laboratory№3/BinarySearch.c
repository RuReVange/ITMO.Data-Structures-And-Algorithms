#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <strings.h>

int binary_search_left_side(int* arr, int value, int len){
    int left = -1;
    int right = len;
    while (left < (right -1)){
        int mid = (left + right)/2;
        int guess = arr[mid];
        if (guess < value){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    return (arr[right] == value ? right+1 : -1);
}

int binary_search_right_side(int* arr, int value, int len){
    int left = -1;
    int right = len;
    while (left < (right -1)){
        int mid = (left + right)/2;
        int guess = arr[mid];
        if (guess <= value){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    return (arr[right-1] == value ? right : -1);
}

int main() {
    int len;
    scanf("%d", &len);

    int arr[len];
    for (int i = 0;i<len; i++){
        scanf("%d", &arr[i]);
    }

    int requests;
    scanf("%d", &requests);

    int arr_requests[requests];
    for (int i =0; i<requests; i++){
        scanf("%d", &arr_requests[i]);
    }


    for (int i = 0; i<requests; i++){
        int left_index = binary_search_left_side(arr, arr_requests[i], len);
        int right_index = binary_search_right_side(arr, arr_requests[i], len);
        printf("%d %d\n", left_index, right_index);
    }

    return 0;
}