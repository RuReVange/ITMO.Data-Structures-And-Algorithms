#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Node{
    char key;
    struct Node* prev;
};

struct Node *push(struct Node *top, char value){
    struct Node *new_top = (struct Node*)malloc(sizeof(struct Node));
    new_top -> key = value;
    new_top -> prev = top;
    top = new_top;
    return top;
}

struct Node *pop(struct Node *top){
    top = top -> prev;
    return top;
}

int main(){
    struct Node *top = malloc(sizeof(struct Node));
    struct Node *head = top;

    char arr[10001];

    while(scanf("%s", &arr)!= EOF){
        while (top != head) {
            top = pop(top);
        }
        int is_valid_flag = 1;
        int len = strlen(arr);
        for (int iter = 0; iter < len; iter++) {
            if ((arr[iter] == '(') || (arr[iter] == '[')) {
                top = push(top, arr[iter]);
            }

            if (arr[iter] == ')' || arr[iter] == ']') {
                if (head == top) {
                    is_valid_flag = 0;
                    break;
                }

                if (top->key == '(' && arr[iter] == ')') {
                    top = pop(top);
                    continue;
                }
                if (top->key == '[' && arr[iter] == ']') {
                    top = pop(top);
                    continue;
                }
                is_valid_flag = 0;
                break;
            }
        }
        if (is_valid_flag == 1 && head == top) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}