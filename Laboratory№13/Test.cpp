#include <iostream>
#include <vector>
using  namespace std;

struct element{
    int isu = -1;
    int points = -1;
    int group = -1;
    char deleted = 0;
};

int sizeTable = 100000;

int h(int& key_group, int& i){
    return ((key_group+3*i+2*i*i) % sizeTable);
}

void hash_insert(vector<struct element>& hashTable, int& key_group, int& isu, int& points){
    int i = 0;
    while (i!=sizeTable){
        int j = h(key_group, i);
        if (hashTable[j].isu == -1 || hashTable[j].deleted == 1){
            hashTable[j].isu = isu;
            hashTable[j].points = points;
            hashTable[j].group = key_group;
            hashTable[j].deleted = 0;
            return;
        }
        else { ++i; }
    }
}

void hash_delete(vector<struct element>& hashTable, int& key_group, int& isu){
    int i = 0;
    while (i!=sizeTable){
        int j = h(key_group, i);
        if (hashTable[j].isu == -1){
            return;
        }
        if (hashTable[j].isu == isu){
            hashTable[j].deleted = 1;
            return;
        }
        else{ ++i; }
    }
}

long getAverage(vector<struct element>& hashTable, int& key_group){
    int i = 0;
    long result;
    long sum = 0;
    int counter = 0;
    while (i!=sizeTable){
        int j = h(key_group, i);
        if (hashTable[j].isu == -1){
            result = sum/counter;
            return result;
        }
        if (hashTable[j].group == key_group && hashTable[j].deleted == 0){
            sum += hashTable[j].points;
            ++counter;
        }
        ++i;
    }
}

long getMax(vector<struct element>& hashTable, int key_group){
    int i = 0;
    int max = 0;

    while (i != sizeTable){
        int j = h(key_group, i);
        if (hashTable[j].isu == -1){
            return max;
        }
        if (hashTable[j].group == key_group && hashTable[j].deleted == 0){
            if(hashTable[j].points > max){
                max = hashTable[j].points;
            }
        }
        ++i;
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, q;
    cin >> m >> q;

    vector<struct element> hashTable (sizeTable);

    char request;
    int tmpGroup, tmpIsu, tmpPoints;
    for (int iter = 0; iter < q; ++iter){
        cin >> request;
        if (request == '+'){
            cin >> tmpGroup >> tmpIsu >> tmpPoints;
            hash_insert(hashTable, tmpGroup, tmpIsu, tmpPoints);
        }
        if (request == '-'){
            cin >> tmpGroup >> tmpIsu;
            hash_delete(hashTable, tmpGroup, tmpIsu);
        }
        if (request == 'a'){
            cin >> tmpGroup;
            cout << getAverage(hashTable, tmpGroup) << "\n";
        }
        if (request == 'm'){
            cin >> tmpGroup;
            cout << getMax(hashTable, tmpGroup) << "\n";
        }
    }

    return 0;
}