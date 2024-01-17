#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node* insert(struct Node* x, int value){
    if (x == NULL){
        struct Node* tmp = malloc(sizeof(struct Node));
        tmp -> key = value;
        tmp-> right = NULL;
        tmp -> left = NULL;
        return tmp;
    }
    else if (value < x -> key){
        x->left = insert(x -> left, value);
    }
    else if (value > x->key){
        x->right = insert(x -> right, value);
    }
    return x;
}

struct Node* search(struct Node* x, int value){
    if (x == NULL || value == x ->key){
        return x;
    }
    if (value < x->key){
        return search(x->left, value);
    }
    else {
        return search(x->right, value);
    }
}

struct Node* minimum(struct Node* x){
    if (x -> left == NULL){
        return x;
    }
    return minimum(x->left);
}

struct Node* next(struct Node* root, int value){
    struct Node *cur = root;
    struct Node *successor = NULL;
    while(cur != NULL){
        if(cur->key > value){
            successor = cur;
            cur = cur->left;
        }
        else {
            cur = cur->right;}
    }
    return successor;
}

struct Node* prev(struct Node* root, int value){
    struct Node *cur = root;
    struct Node *successor = NULL;
    while (cur != NULL) {
        if (cur->key < value){
            successor = cur;
            cur = cur -> right;
        }
        else {
            cur = cur -> left;}
    }
    return successor;
}

struct Node* delete(struct Node* root, int value) {
    if (root == NULL)
        return root;
    if (value < root->key)
        root->left = delete(root->left, value);
    else if(value > root->key)
        root->right = delete(root->right, value);
    else if(root->left != NULL && root->right != NULL){
        root->key = minimum(root->right)->key;
        root->right = delete(root->right, root->key);
    }
    else{
        if (root->left != NULL)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}


int main() {
    struct Node* root = NULL;

    char arr_request[10];
    int value_of_request;

    while(scanf("%s", &arr_request)!= EOF){
        if (arr_request[0] == 'i'){
            scanf("%d", &value_of_request);
            root = insert(root, value_of_request);
        }
        if (arr_request[0] == 'e'){
            scanf("%d", &value_of_request);
            if(search(root, value_of_request)==NULL){
                printf("false\n");
            } else {
                printf("true\n");
            }
        }
        if (arr_request[0] == 'n'){
            scanf("%d", &value_of_request);
            struct Node* tmp = next(root, value_of_request);
            if (tmp == NULL){
                printf("none\n");
            }
            else {
                printf("%d\n", tmp -> key);
            }

        }
        if (arr_request[0] == 'p'){
            scanf("%d", &value_of_request);
            struct Node* tmp = prev(root, value_of_request);
            if (tmp == NULL){
                printf("none\n");
            }
            else {
                printf("%d\n", tmp -> key);
            }
        }
        if (arr_request[0] == 'd'){
            scanf("%d", &value_of_request);
            root = delete(root, value_of_request);
        }
    }

    return 0;
}