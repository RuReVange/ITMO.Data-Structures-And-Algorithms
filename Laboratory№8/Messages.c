#include <stdio.h>
#include <stdlib.h>

struct Node {
    char value;
    int left;
    int right;
    struct Node *next;
    struct Node *prev;
};

int main() {

    int lenMsg1, lenMsg2;
    int k;
    scanf("%d %d %d", &lenMsg1, &lenMsg2, &k);

    char arr1[lenMsg1];
    char arr2[lenMsg2];
    scanf("%s", arr1);
    scanf("%s", arr2);

    if (lenMsg1 == 0 || lenMsg2 == 0){
        if (k > 0){
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    else {

        struct Node *structArr1 = malloc(sizeof(struct Node));
        structArr1->left = 1;
        structArr1->prev = NULL;
        struct Node *head1 = structArr1;
        struct Node *structArr2 = malloc(sizeof(struct Node));
        structArr2->left = 1;
        structArr2->prev = NULL;
        struct Node *head2 = structArr2;

        int i = 0;
        int tmp = 0;
        while (i < lenMsg1) {
            if (arr1[i] < '0' || arr1[i] > '9') {
                structArr1->value = arr1[i];
                tmp = 0;
                i++;
            } else {
                while (arr1[i] >= '0' && arr1[i] <= '9') {
                    tmp = tmp * 10 + (arr1[i] - 48);
                    i++;
                }
                if (structArr1->prev == NULL) {
                    structArr1->right = tmp;
                    if (i != lenMsg1) {
                        struct Node *newNode = malloc(sizeof(struct Node));
                        structArr1->next = newNode;
                        newNode->prev = structArr1;
                        structArr1 = newNode;
                    } else {
                        structArr1->next = NULL;
                    }
                } else {
                    if (i == lenMsg1) {
                        structArr1->left = structArr1->prev->right + 1;
                        structArr1->right = structArr1->prev->right + tmp;
                        structArr1->next = NULL;
                    } else {
                        structArr1->left = structArr1->prev->right + 1;
                        structArr1->right = structArr1->prev->right + tmp;
                        struct Node *newNode = malloc(sizeof(struct Node));
                        structArr1->next = newNode;
                        newNode->prev = structArr1;
                        structArr1 = newNode;
                    }
                }
            }
        }
        i = 0;
        tmp = 0;
        while (i < lenMsg2) {
            if (arr2[i] < '0' || arr2[i] > '9') {
                structArr2->value = arr2[i];
                tmp = 0;
                i++;
            } else {
                while (arr2[i] >= '0' && arr2[i] <= '9') {
                    tmp = tmp * 10 + (arr2[i] - 48);
                    i++;
                }
                if (structArr2->prev == NULL) {
                    structArr2->right = tmp;
                    if (i != lenMsg2) {
                        struct Node *newNode = malloc(sizeof(struct Node));
                        structArr2->next = newNode;
                        newNode->prev = structArr2;
                        structArr2 = newNode;
                    } else {
                        structArr2->next = NULL;
                    }
                } else {
                    if (i == lenMsg2) {
                        structArr2->left = structArr2->prev->right + 1;
                        structArr2->right = structArr2->prev->right + tmp;
                        structArr2->next = NULL;
                    } else {
                        structArr2->left = structArr2->prev->right + 1;
                        structArr2->right = structArr2->prev->right + tmp;
                        struct Node *newNode = malloc(sizeof(struct Node));
                        structArr2->next = newNode;
                        newNode->prev = structArr2;
                        structArr2 = newNode;
                    }
                }
            }
        }
        int kErr = 0;
        int currIter = 0;
        structArr1 = head1;
        structArr2 = head2;
        while (structArr1->next != NULL && structArr2->next != NULL) {

            if (structArr1->value != structArr2->value) {

                if (structArr1->right < structArr2->right) {
                    kErr += structArr1->right - currIter;
                    currIter = structArr1->right;
                    structArr1 = structArr1->next;
                    continue;
                }
                if (structArr2->right < structArr1->right) {
                    kErr += structArr2->right - currIter;
                    currIter = structArr2->right;
                    structArr2 = structArr2->next;
                    continue;
                }
                if (structArr1->right == structArr2->right) {
                    kErr += structArr1->right - currIter;
                    currIter = structArr1->right;
                    structArr1 = structArr1->next;
                    structArr2 = structArr2->next;
                    continue;
                }
            }

            if (structArr1->value == structArr2->value) {

                if (structArr1->right < structArr2->right) {
                    currIter = structArr1->right;
                    structArr1 = structArr1->next;
                    continue;
                }
                if (structArr2->right < structArr1->right) {
                    currIter = structArr2->right;
                    structArr2 = structArr2->next;
                    continue;
                }
                if (structArr1->right == structArr2->right) {
                    currIter = structArr1->right;
                    structArr1 = structArr1->next;
                    structArr2 = structArr2->next;
                    continue;
                }
            }
        }

        if (structArr1->next == NULL && structArr2->next != NULL) {
            while (structArr2->next != NULL) {
                if (structArr1->value != structArr2->value) {
                    kErr += structArr2->right - currIter;
                    currIter = structArr2->right;
                    structArr2 = structArr2->next;
                } else {
                    currIter = structArr2->right;
                    structArr2 = structArr2->next;
                }
            }
            if (structArr1->value != structArr2->value) {
                kErr += structArr2->right - currIter;
                currIter = structArr2->right;
            } else {
                currIter = structArr2->right;
            }
        }

        if (structArr2->next == NULL && structArr1->next != NULL) {
            while (structArr1->next != NULL) {
                if (structArr1->value != structArr2->value) {
                    kErr += structArr1->right - currIter;
                    currIter = structArr1->right;
                    structArr1 = structArr1->next;
                } else {
                    currIter = structArr1->right;
                    structArr1 = structArr1->next;
                }
            }
            if (structArr1->value != structArr2->value) {
                kErr += structArr1->right - currIter;
                currIter = structArr1->right;
            } else {
                currIter = structArr1->right;
            }
        }

        if (kErr < k) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}