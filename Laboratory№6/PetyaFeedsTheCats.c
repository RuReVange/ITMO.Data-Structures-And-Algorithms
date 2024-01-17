#include <stdio.h>
#include <math.h>

struct Node{
    int key;
    int right;
    int left;
};

void buildSegmentedTree (struct Node* SegmentedTree, int* arr, int node, int tleft, int tright) {
    if (tleft == tright) {
        SegmentedTree[node].key = 0;
        SegmentedTree[node].left = tleft;
        SegmentedTree[node].right = tright;
        return;
    }
    else {
        int tmid = (tleft + tright) / 2;
        buildSegmentedTree(SegmentedTree, arr, 2 * node + 1, tleft, tmid);
        buildSegmentedTree(SegmentedTree, arr, 2 * node + 2, tmid + 1, tright);
        SegmentedTree[node].key = SegmentedTree[2 * node + 1].key + SegmentedTree[2 * node + 2].key;
        SegmentedTree[node].left = tleft;
        SegmentedTree[node].right = tright;
    }
}

void update (struct Node* SegmentedTree, int node, int position, int value) {
    if (SegmentedTree[node].left == SegmentedTree[node].right) {
        SegmentedTree[node].key += value;
        if (SegmentedTree[node].key < 0) {
            SegmentedTree[node].key = 0;
        }
        return;
    }
    else if (position <= (SegmentedTree[node].left + SegmentedTree[node].right) /2) {
        update(SegmentedTree, 2 * node + 1, position, value);
    }
    else {
        update(SegmentedTree, 2 * node + 2, position, value);
    }

    SegmentedTree[node].key = SegmentedTree[2 * node + 1].key + SegmentedTree[2 * node + 2].key;

}

int request (struct Node* SegmentedTree, int node, int tleft, int tright) {
    if ( tright < SegmentedTree[node].left || tleft > SegmentedTree[node].right) {
        return 0;
    }

    else if (SegmentedTree[node].left >= tleft && SegmentedTree[node].right <= tright) {
        return SegmentedTree[node].key;
    }
    else {
        return request(SegmentedTree, 2 * node + 1, tleft , tright) + request(SegmentedTree, 2 * node + 2, tleft, tright);
    }
}

int main() {

    int count_of_cats;
    int acts;
    scanf("%d", &count_of_cats);
    scanf("%d", &acts);

    char buffer[2];
    int arr[count_of_cats];
    struct Node SegmentedTree[4*count_of_cats];

    for(int i = 0; i<count_of_cats; i++){
        arr[i]=0;
    }
    buildSegmentedTree(SegmentedTree, arr, 0, 0, count_of_cats);

    int key;
    int left; int right;
    int index;

    for (int i = 0; i < acts; i++){

        scanf("%s", &buffer);

        if (buffer[0] == '+'){
            scanf("%d %d", &index, &key);
            update(SegmentedTree, 0, index, key);

        }
        if (buffer[0] == '-'){
            scanf("%d %d", &index, &key);
            update(SegmentedTree, 0, index, -key);
        }
        if (buffer[0] == '?'){
            scanf("%d %d", &left, &right);
            printf("%d\n", request(SegmentedTree, 0, left, right));
        }
    }

    return 0;
}