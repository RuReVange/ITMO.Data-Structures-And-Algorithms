#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *prev;
};

struct Node *push(struct Node *top, int value){
    struct Node *newTop = (struct Node*) malloc(sizeof(struct Node));
    newTop -> prev = top;
    newTop -> key = value;
    top = newTop;
    return top;
}

struct Node *pop(struct Node *top){
    printf("%d\n", top ->key);
    top = top -> prev;
    return top;
}

int main() {
    struct Node *top = (struct Node*) malloc(sizeof(struct Node));

    int n;
    char action;
    int value;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c", &action);
        if (action == '+') {
            scanf("%d", &value);
            top = push(top, value);
        }
        else {
            top = pop(top);
        }
    }

    return 0;
}