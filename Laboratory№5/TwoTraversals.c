#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};

void Post_order_Travers(int* preorder_arr, int n, int left_border, int right_border, int* iter){
    if (*iter == n){
        return;
    }
    if (preorder_arr[*iter] < left_border || preorder_arr[*iter] > right_border){
        return;
    }
    int cur = preorder_arr[*iter];
    *(iter)+=1;
    Post_order_Travers(preorder_arr, n, left_border, cur, iter);
    Post_order_Travers(preorder_arr, n, cur, right_border, iter);
    printf("%d ", cur);
}

int main() {

    int n;
    scanf("%d", &n);

    int preorder_arr[n];
    for (int i = 0; i< n; i++){
        scanf("%d", &preorder_arr[i]);
    }
    int iterator = 0;
    Post_order_Travers(preorder_arr, n, -1000000, 1000000, &iterator);

    return 0;
}
