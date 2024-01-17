#include <stdio.h>

void min_heapify(int arr[][2], int index, int heap_size){
    int minimum;
    int l = 2*index + 1;
    int r = 2*index + 2;
    if (l < heap_size && arr[l][0] < arr[index][0]){
        minimum = l;
    }
    else {
        minimum = index;
    }
    if (r < heap_size && arr[r][0] < arr[minimum][0]){
        minimum = r;
    }
    if (minimum != index){
        int tmp[2];
        tmp[0] = arr[index][0];
        tmp[1] = arr[index][1];
        arr[index][0] = arr[minimum][0];
        arr[index][1] = arr[minimum][1];
        arr[minimum][0] = tmp[0];
        arr[minimum][1] = tmp[1];
        min_heapify(arr, minimum, heap_size);

    }
}

void heap_extract_min(int arr[][2], int* p_heap_size){
    char star = '*';
    if ((*p_heap_size) < 1){
        printf("%c\n", star);
    }
    else {
        int min = arr[0][0];
        arr[0][0] = arr[(*p_heap_size) - 1][0];
        arr[0][1] = arr[(*p_heap_size) - 1][1];
        (*p_heap_size) -=1;
        min_heapify(arr, 0, (*p_heap_size));
        printf("%d\n", min);
    }
}

void heap_decrease_key_for_value(int arr[][2], int stream, int key, int* p_heap_size) {
    int i;
    for (int j = 0; j < (*p_heap_size); j++) {
        if (arr[j][1] == stream){
            i = j;
            break;
        }
    }
    if (key > arr[i][0]){
        printf("The new key are bigger then current");
    }
    else {
        arr[i][0] = key;
        while (i > 0 && arr[(i-1)/2][0] > arr[i][0]){
            int tmp[2];
            tmp[0] = arr[i][0];
            tmp[1] = arr[i][1];
            arr[i][0] = arr[(i-1)/2][0];
            arr[i][1] = arr[(i-1)/2][1];
            arr[(i-1)/2][0] = tmp[0];
            arr[(i-1)/2][1] = tmp[1];
            i = (i-1)/2;
        }
    }
}

void heap_decrease_key_for_index(int arr[][2], int i, int key){
    if (key > arr[i][0]){
        printf("The new key are bigger then current");
    }
    else {
        arr[i][0] = key;
        while (i > 0 && arr[(i-1)/2][0] > arr[i][0]){
            int tmp[2];
            tmp[0] = arr[i][0];
            tmp[1] = arr[i][1];
            arr[i][0] = arr[(i-1)/2][0];
            arr[i][1] = arr[(i-1)/2][1];
            arr[(i-1)/2][0] = tmp[0];
            arr[(i-1)/2][1] = tmp[1];
            i = (i-1)/2;
        }
    }
}

void min_heap_insert(int arr[][2], int key, int number_of_stream,int* p_heap_size){
    (*p_heap_size) += 1;
    arr[(*p_heap_size) - 1][0] = 1000000000;
    arr[(*p_heap_size) - 1][1] = number_of_stream;
    heap_decrease_key_for_index(arr, (*p_heap_size) - 1, key);
}

int main() {
    int heap_size = 0;

    int counter = 1;
    int arr[100000][2];
    //int line_of_cIn_arr[100000];
    char requests_arr[20];
    int push_x;
    int line_of_stream;
    int y;

    while (scanf("%s", &requests_arr) != EOF) {

        if (requests_arr[0] == 'p'){
            scanf("%d", &push_x);
            min_heap_insert(arr, push_x,counter ,&heap_size);
            //line_of_cIn_arr[counter] = push_x;
            counter += 1;
        }

        if (requests_arr[0] == 'e'){
            heap_extract_min(arr, &heap_size);
            counter += 1;
        }

        if (requests_arr[0] == 'd'){
            scanf("%d", &line_of_stream);
            scanf("%d", &y);
            heap_decrease_key_for_value(arr, line_of_stream, y, &heap_size);
            counter += 1;
        }
    }

    return 0;
}