#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};

struct Node* maximum(struct Node* x){
    if (x -> right == NULL){
        return x;
    }
    return maximum(x->right);
}

struct Node* prev(struct Node* x){
    if (x->left != NULL){
        return maximum(x->left);
    }
    struct Node* y;
    y = x->parent;
    while (y!=NULL && x == y->left){
        x = y;
        y = y->parent;
    }
    return y;
}

int main() {

    struct Node* cur = NULL;

    int n;
    scanf("%d", &n);
    int key;
    int number_of_left, number_of_right;


    struct Node arr_of_Trees_Nodes[n+1];

    for (int i = 1; i <= n; i++) {
        cur = &arr_of_Trees_Nodes[i];
        if (i == 1) {
            cur->parent = NULL;
        }
        scanf("%d", &number_of_left);
        scanf("%d", &number_of_right);

        if (number_of_left == 0) {
            cur->left = NULL;
        } else {
            cur->left = &arr_of_Trees_Nodes[number_of_left];
            cur->left->parent = cur;
        }
        if (number_of_right == 0) {
            cur->right = NULL;
        } else {
            cur->right = &arr_of_Trees_Nodes[number_of_right];
            cur->right->parent = cur;
        }

    }

    struct Node* tmp = maximum(&arr_of_Trees_Nodes[1]);
    for (int i = n; i > 0; i--){
        tmp -> key = i;
        tmp = prev(tmp);
    }

    for (int i = 1; i<=n; i++) {
        printf("%d ", (arr_of_Trees_Nodes+i) -> key);
    }
    return 0;
}