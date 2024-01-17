#include <stdio.h>
#include <stdlib.h>

struct NodeInteger{
    int key;
    int position;
    struct NodeInteger* left;
    struct NodeInteger* right;
    struct NodeInteger* parent;
};

struct NodeCharacter{
    char key;
    int position;
    struct NodeCharacter *left;
    struct NodeCharacter *right;
    struct NodeCharacter *parent;
};

struct NodeInteger* rootSearcherInt(struct NodeInteger* x){
    if (x->parent != NULL){
        rootSearcherInt(x->parent);
    }
    else {
        return x;
    }
}

struct NodeCharacter* rootSearcherChar(struct NodeCharacter* x){
    if (x->parent != NULL){
        rootSearcherChar(x->parent);
    }
    else {
        return x;
    }
}

struct NodeInteger* resultNodeInt = NULL;

struct NodeInteger* NodeSearcherInt(struct NodeInteger* x, int position){
    if (x != NULL && resultNodeInt == NULL){
        if (x->position == position){
            resultNodeInt = x;
        }
        else {
            NodeSearcherInt(x->left, position);
            NodeSearcherInt(x->right, position);
        }
    }

}

struct NodeCharacter* resultNodeChar = NULL;

struct NodeCharacter* NodeSearcherChar(struct NodeCharacter* x, int position){
    if (x != NULL && resultNodeChar == NULL){
        if (x->position == position){
            resultNodeChar = x;
        }
        else {
            NodeSearcherChar(x->left, position);
            NodeSearcherChar(x->right, position);
        }
    }
}

struct NodeInteger* changerInt(struct NodeInteger* x){
    if (x->parent != NULL){
        struct NodeInteger* tmpParent = NULL;

        if (x->parent->parent != NULL && x->parent->parent->left == x->parent){

            if (x->parent->left == x){
                tmpParent = x->parent;
                tmpParent->left = x->left;
                if (x->left != NULL) {
                    x->left->parent = tmpParent;
                    x->left = NULL;
                }
                x->parent->parent->left = x;
                x->parent = x->parent->parent;
                x->left = tmpParent;
                tmpParent->parent = x;
                return rootSearcherInt(x);
            }
            if (x->parent->right == x){
                tmpParent = x->parent;
                tmpParent->right = x->right;
                if (x->right != NULL){
                    x->right->parent = tmpParent;
                    x->right = NULL;
                }
                x->parent->parent->left = x;
                x->parent = x->parent->parent;
                x->right = tmpParent;
                tmpParent->parent = x;
                return rootSearcherInt(x);
            }
        }
        if (x->parent->parent != NULL && x->parent->parent->right == x->parent){

            if (x->parent->left == x){
                tmpParent = x->parent;
                tmpParent->left = x->left;
                if (x->left != NULL) {
                    x->left->parent = tmpParent;
                    x->left = NULL;
                }
                x->parent->parent->right = x;
                x->parent = x->parent->parent;
                x->left = tmpParent;
                tmpParent->parent = x;
                return rootSearcherInt(x);
            }
            if (x->parent->right == x){
                tmpParent = x->parent;
                tmpParent->right = x->right;
                if (x->right != NULL){
                    x->right->parent = tmpParent;
                    x->right = NULL;
                }
                x->parent->parent->right = x;
                x->parent = x->parent->parent;
                x->right = tmpParent;
                tmpParent->parent = x;
                return rootSearcherInt(x);
            }
        }
        if (x->parent->parent == NULL){

            if (x->parent->left == x){
                tmpParent = x->parent;
                tmpParent->left = x->left;
                if (x->left != NULL) {
                    x->left->parent = tmpParent;
                    x->left = NULL;
                }
                x->parent = NULL;
                x->left = tmpParent;
                tmpParent->parent = x;
                return rootSearcherInt(x);
            }
            if (x->parent->right == x){
                tmpParent = x->parent;
                tmpParent->right = x->right;
                if (x->right != NULL){
                    x->right->parent = tmpParent;
                    x->right = NULL;
                }
                x->parent = NULL;
                x->right = tmpParent;
                tmpParent->parent = x;
                return rootSearcherInt(x);
            }
        }
    }
    return rootSearcherInt(x);
}

struct NodeCharacter* changerChar(struct NodeCharacter* x){
    if (x->parent != NULL){
        struct NodeCharacter* tmpParent = NULL;

        if (x->parent->parent != NULL && x->parent->parent->left == x->parent){

            if (x->parent->left == x){
                tmpParent = x->parent;
                tmpParent->left = x->left;
                if (x->left != NULL) {
                    x->left->parent = tmpParent;
                    x->left = NULL;
                }
                x->parent->parent->left = x;
                x->parent = x->parent->parent;
                x->left = tmpParent;
                tmpParent->parent = x;
                return rootSearcherChar(x);
            }
            if (x->parent->right == x){
                tmpParent = x->parent;
                tmpParent->right = x->right;
                if (x->right != NULL){
                    x->right->parent = tmpParent;
                    x->right = NULL;
                }
                x->parent->parent->left = x;
                x->parent = x->parent->parent;
                x->right = tmpParent;
                tmpParent->parent = x;
                return rootSearcherChar(x);
            }
        }
        if (x->parent->parent != NULL && x->parent->parent->right == x->parent){

            if (x->parent->left == x){
                tmpParent = x->parent;
                tmpParent->left = x->left;
                if (x->left != NULL) {
                    x->left->parent = tmpParent;
                    x->left = NULL;
                }
                x->parent->parent->right = x;
                x->parent = x->parent->parent;
                x->left = tmpParent;
                tmpParent->parent = x;
                return rootSearcherChar(x);
            }
            if (x->parent->right == x){
                tmpParent = x->parent;
                tmpParent->right = x->right;
                if (x->right != NULL){
                    x->right->parent = tmpParent;
                    x->right = NULL;
                }
                x->parent->parent->right = x;
                x->parent = x->parent->parent;
                x->right = tmpParent;
                tmpParent->parent = x;
                return rootSearcherChar(x);
            }
        }
        if (x->parent->parent == NULL){

            if (x->parent->left == x){
                tmpParent = x->parent;
                tmpParent->left = x->left;
                if (x->left != NULL) {
                    x->left->parent = tmpParent;
                    x->left = NULL;
                }
                x->parent = NULL;
                x->left = tmpParent;
                tmpParent->parent = x;
                return rootSearcherChar(x);
            }
            if (x->parent->right == x){
                tmpParent = x->parent;
                tmpParent->right = x->right;
                if (x->right != NULL){
                    x->right->parent = tmpParent;
                    x->right = NULL;
                }
                x->parent = NULL;
                x->right = tmpParent;
                tmpParent->parent = x;
                return rootSearcherChar(x);
            }
        }
    }
    return rootSearcherChar(x);
}

int counter = 0;

void postOrderTraversalInt(struct NodeInteger* x, int* arrInt){
    if (x != NULL){
        postOrderTraversalInt(x->left, arrInt);
        postOrderTraversalInt(x->right, arrInt);
        arrInt[counter] = x->key;
        counter++;
    }
}

void postOrderTraversalChar(struct NodeCharacter* x, char* arrChar){
    if (x != NULL){
        postOrderTraversalChar(x->left, arrChar);
        postOrderTraversalChar(x->right, arrChar);
        arrChar[counter] = x->key;
        counter++;
    }
}


int main() {

    int n, changeCounter1, changeCounter2;
    int changePosition;
    scanf("%d %d", &n, &changeCounter1);

    struct NodeInteger arrTreeInt[n+1];
    struct NodeCharacter arrTreeChar[n+1];
    arrTreeInt[1].parent = NULL;
    arrTreeInt[1].left = NULL;
    arrTreeInt[1].right = NULL;
    struct NodeInteger* rootInt = &arrTreeInt[1];

    arrTreeChar[1].parent = NULL;
    arrTreeChar[1].left = NULL;
    arrTreeChar[1].right = NULL;
    struct NodeCharacter* rootChar = &arrTreeChar[1];

    for (int i = 1; i <= n; ++i){
        if (i*2 <= n || i*2+1 <= n){
            if (i*2 <= n){
                arrTreeInt[i].left = &arrTreeInt[i*2];
                arrTreeInt[i*2].parent = &arrTreeInt[i];
                arrTreeInt[i*2].left = NULL;
                arrTreeInt[i*2].right = NULL;
                if (i*2 + 1 > n){
                    arrTreeInt[i].right = NULL;
                }
            }
            if (i*2+1 <= n){
                arrTreeInt[i].right = &arrTreeInt[i*2+1];
                arrTreeInt[i*2+1].parent = &arrTreeInt[i];
                arrTreeInt[i*2+1].left = NULL;
                arrTreeInt[i*2+1].right = NULL;
            }
        }
        else {
            break;
        }
    }

    for (int i = 1; i<=n; ++i){
        scanf("%d", &arrTreeInt[i].key);
        arrTreeInt[i].position = i;
    }

    for (int i = 0; i< changeCounter1; ++i){
        scanf("%d", &changePosition);
        NodeSearcherInt(rootInt, changePosition);
        rootInt = changerInt(resultNodeInt);
        resultNodeInt = NULL;
    }

    scanf("%d %d", &n, &changeCounter2);

    for (int i = 1; i <= n; ++i){
        if (i*2 <= n || i*2+1 <= n){
            if (i*2 <= n){
                arrTreeChar[i].left = &arrTreeChar[i*2];
                arrTreeChar[i*2].parent = &arrTreeChar[i];
                arrTreeChar[i*2].left = NULL;
                arrTreeChar[i*2].right = NULL;
                if (i*2 + 1 > n){
                    arrTreeChar[i].right = NULL;
                }
            }
            if (i*2+1 <= n){
                arrTreeChar[i].right = &arrTreeChar[i*2+1];
                arrTreeChar[i*2+1].parent = &arrTreeChar[i];
                arrTreeChar[i*2+1].left = NULL;
                arrTreeChar[i*2+1].right = NULL;
            }
        }
        else {
            break;
        }
    }

    for (int i = 1; i<=n; ++i){
        scanf(" %c", &arrTreeChar[i].key);
        arrTreeChar[i].position = i;
    }

    for (int i = 0; i< changeCounter2; ++i){
        scanf("%d", &changePosition);
        NodeSearcherChar(rootChar, changePosition);
        rootChar = changerChar(resultNodeChar);
        resultNodeChar = NULL;
    }

    int resultInt[n];
    postOrderTraversalInt(rootInt, resultInt);
    counter = 0;
    char resultChar[n];
    postOrderTraversalChar(rootChar, resultChar);

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < resultInt[i]; ++j){
            printf("%c", resultChar[i]);
        }
    }
    free(resultNodeInt);
    free(resultNodeChar);


    return 0;
}