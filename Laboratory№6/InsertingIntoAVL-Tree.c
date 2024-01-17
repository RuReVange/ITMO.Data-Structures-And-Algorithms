#include <stdio.h>

struct Node{
    int key;
    int left;
    int right;
    int height_of_node;
    int balance;
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
        arr_of_Trees_Nodes[i].balance = arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].right].height_of_node - arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].height_of_node;
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

void BigRotateRight(struct Node* arr_of_Trees_Nodes, int index_of_rotate_Node, int index_of_change_Node, int mid_Node) {
    rotateleft(arr_of_Trees_Nodes, mid_Node, index_of_change_Node);
    rotateright(arr_of_Trees_Nodes, index_of_rotate_Node, mid_Node);
}

int flag = 1;

int insert(struct Node* arr_of_Trees_Nodes, int n, int i, int z) {

    if (i == 0) {
        arr_of_Trees_Nodes[n].key = z;
        arr_of_Trees_Nodes[n].left = 0;
        arr_of_Trees_Nodes[n].right = 0;
        arr_of_Trees_Nodes[n].height_of_node = 1;
        arr_of_Trees_Nodes[n].balance = 0;
        return n;
    }

    else if (z < arr_of_Trees_Nodes[i].key) {
        arr_of_Trees_Nodes[i].left = insert(arr_of_Trees_Nodes, n, arr_of_Trees_Nodes[i].left, z);

        arr_of_Trees_Nodes[i].height_of_node = 1 + max(arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].right].height_of_node , arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].height_of_node);

        arr_of_Trees_Nodes[i].balance = arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].right].height_of_node - arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].height_of_node;
        //printf("i = %d  h = %d b = %d\n left.h = %d", i, arr_of_Trees_Nodes[i].h, arr_of_Trees_Nodes[i].balance, arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].h);
        if (flag) {

            if(arr_of_Trees_Nodes[i].balance == 2 && arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].right].balance == -1) {
                BigRotateLeft(arr_of_Trees_Nodes, i, arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].right].left, arr_of_Trees_Nodes[i].right);
                flag--;
            }

            if(arr_of_Trees_Nodes[i].balance == 2 && (arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].right].balance == 1 || arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].right].balance == 0)) {
                rotateleft(arr_of_Trees_Nodes, i, arr_of_Trees_Nodes[i].right);
                flag--;
            }

            if(arr_of_Trees_Nodes[i].balance == -2 && (arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].balance == -1 || arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].balance == 0) ) {
                rotateright(arr_of_Trees_Nodes, i, arr_of_Trees_Nodes[i].left);
                flag--;
            }

            if(arr_of_Trees_Nodes[i].balance == -2 && arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].balance == 1) {
                BigRotateRight(arr_of_Trees_Nodes, i, arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].right, arr_of_Trees_Nodes[i].left);
                flag--;
            }

        }

    }

    else if (z > arr_of_Trees_Nodes[i].key) {
        arr_of_Trees_Nodes[i].right = insert(arr_of_Trees_Nodes, n, arr_of_Trees_Nodes[i].right, z);
        arr_of_Trees_Nodes[i].height_of_node = 1 + max(arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].right].height_of_node , arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].height_of_node);

        arr_of_Trees_Nodes[i].balance = arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].right].height_of_node - arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].height_of_node;
        if (flag) {

            if(arr_of_Trees_Nodes[i].balance == 2 && arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].right].balance == -1) {
                BigRotateLeft(arr_of_Trees_Nodes, i, arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].right].left, arr_of_Trees_Nodes[i].right);
                flag--;
            }

            if(arr_of_Trees_Nodes[i].balance == 2 && (arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].right].balance == 1 || arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].right].balance == 0)) {
                rotateleft(arr_of_Trees_Nodes, i, arr_of_Trees_Nodes[i].right);
                flag--;
            }

            if(arr_of_Trees_Nodes[i].balance == -2 && (arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].balance == -1 || arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].balance == 0) ) {
                rotateright(arr_of_Trees_Nodes, i, arr_of_Trees_Nodes[i].left);
                flag--;
            }

            if(arr_of_Trees_Nodes[i].balance == -2 && arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].balance == 1) {
                BigRotateRight(arr_of_Trees_Nodes, i, arr_of_Trees_Nodes[arr_of_Trees_Nodes[i].left].right, arr_of_Trees_Nodes[i].left);
                flag--;
            }

        }

    }
    return  i;
}

int main() {

    struct Node* cur = NULL;

    int n;
    scanf("%d", &n);
    int key_of_new_Node;

    if( n == 0) {
        scanf("%d", &key_of_new_Node);
        printf("%d\n", n + 1);
        printf("%d 0 0", key_of_new_Node);
        return 0;
    }

    int key;
    int number_of_left, number_of_right;

    struct Node arr_of_Trees_Nodes[n+2];
    arr_of_Trees_Nodes[0].key = 0;
    arr_of_Trees_Nodes[0].height_of_node = 0;
    arr_of_Trees_Nodes[0].balance = 0;

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


    scanf("%d", &key_of_new_Node);

    insert(arr_of_Trees_Nodes, n+1, 1, key_of_new_Node);

    printf("%d\n", n+1);

    struct Node help_arr_of_Trees_Nodes[n+2];

    struct Node help_Node;
    int son_index = 2;
    help_arr_of_Trees_Nodes[1] = arr_of_Trees_Nodes[1];

    for (int i = 1; i < n+2; i++) {
        help_Node = help_arr_of_Trees_Nodes[i];

        if (help_Node.left != 0) {
            help_arr_of_Trees_Nodes[son_index] = arr_of_Trees_Nodes[help_Node.left];
            son_index+=1;
        }

        if (help_Node.right != 0) {
            help_arr_of_Trees_Nodes[son_index] = arr_of_Trees_Nodes[help_Node.right];
            son_index+=1;
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