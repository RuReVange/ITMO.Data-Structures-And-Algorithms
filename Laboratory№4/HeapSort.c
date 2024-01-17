#include <stdio.h>

void max_heapify(int* arr, int index, int heap_size){
    int largest;
    int l = 2*index + 1;
    int r = 2*index + 2;
    if (l < heap_size && arr[l] > arr[index]){
        largest = l;
    }
    else {
        largest = index;
    }
    if (r < heap_size && arr[r] > arr[largest]){
        largest = r;
    }
    if (largest != index){
        int tmp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = tmp;
        max_heapify(arr, largest, heap_size);
    }
}

void build_max_heap(int *arr, int len){
    int heap_size = len;
    for (int i = len/2; i>=0; i--){
        max_heapify(arr, i, heap_size);
    }
}

void heap_sort(int *arr, int len, int heap_size){
    build_max_heap(arr, len);
    for (int i = len-1; i > 0; i--){
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heap_size -=1;
        max_heapify(arr, 0, heap_size);
    }

    for (int j = 0; j < len; j++) {
        printf("%d ", arr[j]);
    }
}

int main() {

    int n;
    scanf("%d", &n);
    int size = n;

    int arr[n];
    for (int j = 0; j< n; j++) {
        scanf("%d", &arr[j]);
    }

    heap_sort(arr, n, size);

    return 0;

}