#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char name_of_file[1000];
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

void insert(struct Node* x, char* name_of_file){
    struct Node* tmp = malloc(sizeof(struct Node));
    strcpy(tmp -> name_of_file, name_of_file);
    while (x != NULL){
        if(strcmp(name_of_file, x -> name_of_file) > 0){
            if (x->right != NULL){
                x = x->right;
            }
            else {
                tmp->parent = x;
                x->right = tmp;
                break;
            }
        }
        else if (strcmp(name_of_file, x -> name_of_file) < 0){
            if (x->left != NULL){
                x = x->left;
            }
            else {
                tmp->parent = x;
                x->left = tmp;
                break;
            }
        }
    }
}

struct Node* search(struct Node* x, char* name_of_file){
    if (x == NULL || strcmp(name_of_file, x -> name_of_file)==0){
        return x;
    }
    if (strcmp(name_of_file, x -> name_of_file) < 0){
        return search(x->left, name_of_file);
    }
    else {
        return search(x->right, name_of_file);
    }
}

unsigned int summary(struct Node* x, struct Node* another1, struct Node* another2) {
    if (x != NULL) {
        int curr_point;
        if (search(another1, x->name_of_file) != NULL && search(another2, x->name_of_file) != NULL) {
            curr_point = 0;
        } else if (search(another1, x->name_of_file) != NULL || search(another2, x->name_of_file) != NULL) {
            curr_point = 1;
        } else {
            curr_point = 3;
        }
        return summary(x->left, another1, another2) + summary(x->right, another1, another2) + curr_point;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    char file_name[1000];

    struct Node* root1 = malloc(sizeof(struct Node));
    root1 -> parent = NULL;
    root1 -> left = NULL;
    root1 -> right = NULL;
    struct Node* root2 = malloc(sizeof(struct Node));
    root2 -> parent = NULL;
    root2 -> left = NULL;
    root2 -> right = NULL;
    struct Node* root3 = malloc(sizeof(struct Node));
    root3 -> parent = NULL;
    root3 -> left = NULL;
    root3 -> right = NULL;

    for (int i = 0; i<n; i++){
        scanf("%s", file_name);
        if (i == 0){
            strcpy(root1 -> name_of_file, file_name);
        }
        else {
            insert(root1, file_name);
        }
    }
    for (int i = 0; i<n; i++){
        scanf("%s", file_name);
        if (i == 0){
            strcpy(root2 -> name_of_file, file_name);
        }
        else {
            insert(root2, file_name);
        }
    }
    for (int i = 0; i<n; i++){
        scanf("%s", file_name);
        if (i == 0){
            strcpy(root3 -> name_of_file, file_name);
        }
        else {
            insert(root3, file_name);
        }
    }

    printf("%d ", summary(root1, root2, root3));
    printf("%d ", summary(root2, root1, root3));
    printf("%d ", summary(root3, root1, root2));
    return 0;
}
