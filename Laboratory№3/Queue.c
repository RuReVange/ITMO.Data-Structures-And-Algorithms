#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int key;
    struct Node *next;
};

struct Node *enqueue(struct Node *tail, int value){
    struct Node *newTail = (struct Node*)malloc (sizeof(struct Node));
    tail -> next = newTail;
    newTail -> prev = tail;
    newTail -> key = value;
    newTail -> next = NULL;
    tail = newTail;
    return tail;
}

struct Node *dequeue(struct Node *head){
    head = head -> next;
    printf("%d\n", head -> key);

    return head;
}

int main() {
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    struct Node *tail = head;
    int n;
    char action;
    int value;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c", &action);
        if (action == '+') {
            scanf("%d", &value);
            tail = enqueue(tail, value);
        }
        else {
            head = dequeue(head);
        }
    }

    return 0;
}