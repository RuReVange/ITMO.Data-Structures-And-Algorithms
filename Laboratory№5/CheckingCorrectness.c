#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};

int isBinarySearchTree(struct Node* x, int min, int max){
    if (x == NULL){
        return 1;
    }
    if (x->key <= min || max <= x->key){
        return 0;
    }
    return isBinarySearchTree(x->left, min, x->key) && isBinarySearchTree(x->right, x->key, max);
}

int main() {

    struct Node* cur = NULL;

    int n;
    scanf("%d", &n);
    int key;
    int number_of_left, number_of_right;
    int flag;

    struct Node arr_of_Trees_Nodes[n+1];

    if (n == 0 || n == 1){
        printf("YES");
    }

    if (n > 1) {
        for (int i = 1; i <= n; i++) {
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

        flag = isBinarySearchTree(&arr_of_Trees_Nodes[1], -1000000010, 1000000010);

        if (flag == 1){
            printf("YES");
        }
        else {
            printf("NO");
        }

    }

    return 0;
}