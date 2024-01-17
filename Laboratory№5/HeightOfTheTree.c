#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    int hight_of_node;
};

int main() {

    struct Node* cur = NULL;

    int n;
    scanf("%d", &n);
    int key;
    int number_of_left, number_of_right;

    if (n == 0){
        printf("0");
    }
    if (n == 1){
        scanf("%d", &key);
        scanf("%d", &number_of_left);
        scanf("%d", &number_of_right);
        printf("1");
    }
    if (n>1) {
        struct Node arr_of_Trees_Nodes[n+1];
        int max_hight = -1;
        for (int i = 1; i <= n; i++){
            cur = &arr_of_Trees_Nodes[i];
            if (i == 1){
                cur -> parent = NULL;
                cur -> hight_of_node = 1;
            }

            scanf("%d", &key);
            scanf("%d", &number_of_left);
            scanf("%d", &number_of_right);
            cur -> key = key;
            if (number_of_left == 0){
                cur -> left = NULL;
            }
            else {
                cur->left = &arr_of_Trees_Nodes[number_of_left];
                cur -> left -> parent = cur;
            }
            if (number_of_right == 0){
                cur -> right = NULL;
            }
            else {
                cur->right = &arr_of_Trees_Nodes[number_of_right];
                cur -> right -> parent = cur;
            }
            if (cur -> parent != NULL) {
                cur->hight_of_node = cur->parent->hight_of_node + 1;
            }

            if (cur -> hight_of_node > max_hight){
                max_hight = cur -> hight_of_node;
            }

        }

        printf("%d", max_hight);
    }

    return 0;
}