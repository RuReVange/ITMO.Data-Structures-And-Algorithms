#include <stdio.h>

int max(int left, int right){
    if (left > right) {
        return left;
    }
    else {
        return right;
    }
}

int main() {
    int capacity;
    int gold_block;
    scanf("%d %d", &capacity, &gold_block);

    int keys_goldBlock[gold_block+1];
    for (int i = 1; i<=gold_block; i++){
        scanf("%d", &keys_goldBlock[i]);
    }

    int arr[gold_block+1][capacity+1];
    for (int i = 0; i<= capacity; i++){
        arr[0][i] = 0;
    }
    for (int i = 0; i<= gold_block; i++){
        arr[i][0] = 0;
    }

    for (int k = 1; k<=gold_block; k++){
        for (int s = 1; s<=capacity; s++){
            if (s >= keys_goldBlock[k]){
                arr[k][s] = max(arr[k-1][s], arr[k-1][s - keys_goldBlock[k]] + keys_goldBlock[k]);
            }
            else {
                arr[k][s] = arr[k-1][s];
            }
        }
    }
    printf("%d", arr[gold_block][capacity]);
    return 0;
}
