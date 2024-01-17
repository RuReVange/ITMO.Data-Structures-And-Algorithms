#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int key;
    int left;
    int right;
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

int height(struct Node* arr_of_Trees_Nodes, int i) {
    if (i == 0)
        return 1;
    else {
        arr_of_Trees_Nodes[i].height_of_node = max(height(arr_of_Trees_Nodes, arr_of_Trees_Nodes[i].left),height(arr_of_Trees_Nodes, arr_of_Trees_Nodes[i].right));
        return 1 + arr_of_Trees_Nodes[i].height_of_node;
    }
}

void rotateleft(struct Node* arr_of_Trees_Nodes, int index_of_rotate_Node, int index_of_change_Node) {
    int p = arr_of_Trees_Nodes[index_of_rotate_Node].right;
    arr_of_Trees_Nodes[index_of_rotate_Node].right = arr_of_Trees_Nodes[index_of_change_Node].left;
    arr_of_Trees_Nodes[index_of_change_Node].left = p;

    struct Node pNode = arr_of_Trees_Nodes[index_of_rotate_Node];
    arr_of_Trees_Nodes[index_of_rotate_Node] = arr_of_Trees_Nodes[index_of_change_Node];
    arr_of_Trees_Nodes[index_of_change_Node] = pNode;
}

void rotateright(struct Node* arr_of_Trees_Nodes, int index_of_rotate_Node, int index_of_change_Node) {
    int p = arr_of_Trees_Nodes[index_of_rotate_Node].left;
    arr_of_Trees_Nodes[index_of_rotate_Node].left = arr_of_Trees_Nodes[index_of_change_Node].right;
    arr_of_Trees_Nodes[index_of_change_Node].right = p;

    struct Node pNode = arr_of_Trees_Nodes[index_of_rotate_Node];
    arr_of_Trees_Nodes[index_of_rotate_Node] = arr_of_Trees_Nodes[index_of_change_Node];
    arr_of_Trees_Nodes[index_of_change_Node] = pNode;
}

void BigRotateLeft(struct Node* arr_of_Trees_Nodes, int index_of_rotate_Node, int index_of_change_Node, int mid_Node) {
    rotateright(arr_of_Trees_Nodes, mid_Node, index_of_change_Node);
    rotateleft(arr_of_Trees_Nodes, index_of_rotate_Node, mid_Node);
}

int main() {

    struct Node* cur = NULL;

    int n;
    scanf("%d", &n);
    int key;
    int number_of_left, number_of_right;

    struct Node arr_of_Trees_Nodes[n+1];
    for (int i = 1; i < n+1; i++){
        cur = &arr_of_Trees_Nodes[i];

        scanf("%d", &key);
        scanf("%d", &number_of_left);
        scanf("%d", &number_of_right);
        cur -> key = key;
        cur -> left = number_of_left;
        cur -> right = number_of_right;

    }

    height(arr_of_Trees_Nodes, 1);
    struct Node* root = &arr_of_Trees_Nodes[1];

    if ((root->right==0 ? 0 : arr_of_Trees_Nodes[root->right].height_of_node) - (root->left==0 ? 0 : arr_of_Trees_Nodes[root->left].height_of_node)==2 && arr_of_Trees_Nodes[arr_of_Trees_Nodes[root->right].left].height_of_node <= arr_of_Trees_Nodes[arr_of_Trees_Nodes[root->right].right].height_of_node){
        rotateleft(arr_of_Trees_Nodes, 1, arr_of_Trees_Nodes[1].right);
    }
    if ((root->right==0 ? 0 : arr_of_Trees_Nodes[root->right].height_of_node) - (root->left==0 ? 0 : arr_of_Trees_Nodes[root->left].height_of_node)==2 && arr_of_Trees_Nodes[arr_of_Trees_Nodes[root->right].left].height_of_node > arr_of_Trees_Nodes[arr_of_Trees_Nodes[root->right].right].height_of_node){
        BigRotateLeft(arr_of_Trees_Nodes, 1, arr_of_Trees_Nodes[arr_of_Trees_Nodes[1].right].left, arr_of_Trees_Nodes[1].right);
    }

    printf("%d\n", n);
    struct Node help_arr_of_Trees_Nodes[n+1];

    struct Node help_Node;
    int son_index = 2;
    help_arr_of_Trees_Nodes[1] = arr_of_Trees_Nodes[1];

    for (int i = 1; i <= n; i++) {
        help_Node = help_arr_of_Trees_Nodes[i];

        if (help_Node.left != 0) {
            help_arr_of_Trees_Nodes[son_index] = arr_of_Trees_Nodes[help_Node.left];
            son_index++;
        }

        if (help_Node.right != 0) {
            help_arr_of_Trees_Nodes[son_index] = arr_of_Trees_Nodes[help_Node.right];
            son_index++;
        }
        if (help_Node.left == 0 && help_Node.right == 0){
            printf("%d 0 0\n", help_Node.key);
        }
        else if (help_Node.left == 0 && help_Node.right != 0){
            printf("%d 0 %d\n", help_Node.key, son_index - 1);
        }
        else if (help_Node.left != 0 && help_Node.right == 0){
            printf("%d %d 0\n", help_Node.key, son_index - 1);
        }
        else {
            printf("%d %d %d\n", help_Node.key, son_index - 2, son_index - 1);
        }

    }


    return 0;
}