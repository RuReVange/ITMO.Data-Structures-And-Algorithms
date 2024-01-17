#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Node{
    int key;
    struct Node* prev;
    int max;
};

struct Node *push(struct Node *top, int value){
    struct Node *new_top = (struct Node*)malloc(sizeof(struct Node));
    new_top -> key = value;
    new_top -> prev = top;
    if (value > top -> max){
        new_top -> max = value;
    }
    else{
        (new_top -> max) = (top -> max);
    }
    top = new_top;
    return top;
}

struct Node *pop(struct Node *top){
    top = top -> prev;
    return top;
}

int main() {
    struct Node *top = malloc(sizeof(struct Node));
    struct Node *head = top;
    top -> max = 0;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        char tmp[5];
        scanf("%s", &tmp);
        if (*tmp == '+'){
            int rezult;
            scanf("%d", &rezult);                 //(int)arr[2]-48
            top = push(top, rezult);
        }
        if (*tmp == '-'){
            top = pop(top);
        }
        if (*tmp == 'm'){
            printf("%d\n", (top -> max));
        }
    }
    return 0;
}
