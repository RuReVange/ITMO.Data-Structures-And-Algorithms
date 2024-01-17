#include <iostream>
#include <vector>
using namespace std;
struct element{
    int key = -1;
    bool visited = false;
};

int sizeTable = 50001;

int h(int& key_group, int& i){
    return ((key_group+3*i+2*i*i) % sizeTable);
}

bool hash_find(vector<struct element>& hashTable, int& key)
{
    int i = 0;
    while (i!=sizeTable){
        int j = h(key, i);
        if (!hashTable[j].visited){
            return false;
        }
        if (hashTable[j].key == key){
            return true;
        }
        else { ++i; }
    }
}

void hash_insert(vector<struct element>& hashTable, int& key){
    int i = 0;
    while (i!=sizeTable){
        int j = h(key, i);
        if (!hashTable[j].visited){
            hashTable[j].visited = true;
            hashTable[j].key = key;
            return;
        }
        else { ++i; }
    }
}

int main() {
    int n;
    cin >> n;
    int counter = 0;

    vector<struct element> Ox(sizeTable);
    vector<struct element> Oy(sizeTable);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (!hash_find(Ox, x) && !hash_find(Oy, y)) {
            counter++;
            hash_insert(Ox, x);
            hash_insert(Oy, y);
        }
    }
    if (counter <= 3) {
        cout << "YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}