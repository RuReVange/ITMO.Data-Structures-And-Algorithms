#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    int height_of_node;
};

int max(int left, int right){
    if (left > right) {
        return left;
    }
    else {
        return right;
    }
}

int height(struct Node* x) {
    if (x == NULL)
        return 0;
    else {
        x->height_of_node = 1 + max(height(x->left), height(x->right));
        return x->height_of_node;
    }
}

int main() {

    struct Node* cur = NULL;

    int n;
    scanf("%d", &n);
    int key;
    int number_of_left, number_of_right;

    struct Node arr_of_Trees_Nodes[n+1];
    for (int i = 1; i < n+1; i++) {
        cur = &arr_of_Trees_Nodes[i];
        if (i == 1) {
            cur->parent = NULL;
        }

        scanf("%d", &key);
        scanf("%d", &number_of_left);
        scanf("%d", &number_of_right);
        cur->key = key;
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

    height(&arr_of_Trees_Nodes[1]);
    for (int i = 1; i <= n; i++){
        cur = &arr_of_Trees_Nodes[i];
        printf("%d\n", (cur->right==NULL ? 0 : cur->right->height_of_node) - (cur->left==NULL ? 0 : cur->left->height_of_node));
    }

    return 0;
}