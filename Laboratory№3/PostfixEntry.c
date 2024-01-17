#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int key;
    struct Node *prev;
};

struct Node *push(struct Node *top, int value){
    struct Node *new_top = malloc(sizeof(struct Node));
    new_top ->key = value;
    new_top -> prev = top;
    top = new_top;
    return top;
}

struct Node *pop(struct Node *top){
    top = top ->prev;
    return top;
}

int main() {
    struct Node *top = malloc(sizeof(struct Node));
    struct Node *head = top;

    char arr[101];
    gets(arr);
    int len = strlen(arr);

    int rezult;

    for (int i = 0; i<len; i++){
        if (isdigit(arr[i])){
            int tmp = (int)arr[i]-48;
            top = push(top, tmp);
        }
        else{
            if(arr[i] == '+'){
                rezult  = (top -> key)+((top->prev)->key);
                top = pop(top);
                top = pop(top);
                top = push(top,rezult);
                rezult = 0;
            }
            if(arr[i] == '-'){
                rezult  = (top->prev->key)-(top -> key);
                top = pop(top);
                top = pop(top);
                top = push(top,rezult);
                rezult = 0;
            }
            if(arr[i] == '*'){
                rezult  = (top->prev->key)*(top -> key);
                top = pop(top);
                top = pop(top);
                top = push(top,rezult);
                rezult = 0;
            }
        }
    }
    printf("%d", top -> key);
    return 0;
}