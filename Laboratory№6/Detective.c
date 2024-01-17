#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a)>(b))?(a):(b))

struct Tree {
    int value;
    struct Tree * left;
    struct Tree * right;
    int height;
};
int Height(struct Tree * n ){
    if(n == NULL)
        return -1;
    else
        return n->height;
}

struct Tree * LeftRotate(struct Tree* a ){//малый левый поворот
    struct Tree * b = NULL;

    b = a->right;
    a->right = b->left;
    b->left = a;

    a->height = max(Height(a->left), Height(a->right)) + 1;
    b->height = max(Height(b->left), Height(b->right)) + 1;
    return b;
}
struct Tree * RightRotate(struct Tree * b ){//малый правый поворот
    struct Tree * c;

    c = b->left;
    b->left = c->right;
    c->right = b;

    b->height = max(Height(b->left), Height(b->right)) + 1;
    c->height = max(Height(c->left), Height(c->right)) + 1;

    return c;
}
int getBalance(struct Tree *t){
    if (t == NULL)
        return 0;
    return Height(t->left) - Height(t->right);
}

struct Tree * Insert(struct Tree * t, int x){//добавление в дерево

    if(t == NULL){
        t = (struct Tree*)malloc(sizeof(struct Tree));
        t->value = x;
        t->height = 0;
        t->left = t->right = NULL;
    }
    if (x < t->value)
        t->left  = Insert(t->left, x);
    else if (x > t->value)
        t->right = Insert(t->right, x);
    else
        return t;

    t->height = 1 + max(Height(t->left), Height(t->right));
    //балансировка, если надо
    int balance = getBalance(t);

    if (balance > 1 && x < t->left->value)
        return RightRotate(t);

    if (balance < -1 && x > t->right->value)
        return LeftRotate(t);

    if (balance > 1 && x > t->left->value){
        t->left =  LeftRotate(t->left);
        return RightRotate(t);
    }

    if (balance < -1 && x < t->right->value){
        t->right = RightRotate(t->right);
        return LeftRotate(t);
    }

    return t;
}

struct Tree* Prev(struct Tree* node){//поиск предыдущего элемента
    struct Tree* current = node;

    while (current->right != NULL)
        current = current->right;
    return current;
}
struct Tree* deleteNode(struct Tree * root, int key){//удаление узла
    if (root == NULL)
        return root;

    if (key < root->value)
        root->left = deleteNode(root->left, key);

    else if(key > root->value)
        root->right = deleteNode(root->right, key);

    else{
        if((root->left == NULL) || (root->right == NULL)){//если один или ноль детей
            struct Tree *temp = root->left ? root->left : root->right;
            if (temp == NULL){//если нет детей
                temp = root;
                root = NULL;
            }
            else//если есть один
                *root = *temp;
            free(temp);
        }
        else{//если есть оба ребенка
            struct Tree* temp = Prev(root->left);//заменяем на предыдущий

            root->value = temp->value;
            root->left = deleteNode(root->left, temp->value);//и предыдущий удаляем
        }
    }
    if (root == NULL)
        return root;
    //балансировка, если надо
    root->height = 1 + max(Height(root->left), Height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return RightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0){
        root->left =  LeftRotate(root->left);
        return RightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return LeftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0){
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }

    return root;
}
int Search(struct Tree * t, int x){//поиск элемента, возвращает True, False
    if(t == NULL)
        return 0;
    if(t->value == x)
        return 1;
    if(x > t->value)
        return Search(t->right, x);
    else if(x < t->value)
        return Search(t->left, x);
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    struct Tree * t = NULL;
    int x;
    char operation;
    for(int i = 0;i < n; i++){
        scanf(" %c %d", &operation, &x);
        if(operation == 'A') {//append
            t = Insert(t, x);
            printf("%d\n", -1*getBalance(t));
        }
        if(operation == 'D'){//delete
            t = deleteNode(t, x);
            printf("%d\n", -1 * getBalance(t));
        }
        if(operation == 'C'){//exist
            if(Search(t, x) == 0)
                printf("N\n");
            else
                printf("Y\n");
        }
    }
    return 0;
}