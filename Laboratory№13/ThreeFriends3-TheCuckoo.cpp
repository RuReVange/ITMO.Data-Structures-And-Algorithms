#include <iostream>
#include <random>
#include <string>
using namespace std;

long long m = 1098439;

long long h(string& tmp){
    int result = 0;
    for (int i = 0; i < tmp.length(); ++i){
        result*=151;
        result += (int)tmp[i];
    }
    return result;
}

long long h1(long long& tmp){
    return tmp * 269 % m;
}

long long h2(long long& tmp){
    return tmp * 113 % m;
}

void hash_insert(vector<vector<long long>>& hashTable, long long& key){
    long long tmp;
    if (hashTable[h1(key)].empty()){
        hashTable[h1(key)].emplace_back(key);
    }
    else if (hashTable[h2(key)].empty()){
        hashTable[h2(key)].emplace_back(key);
    }
    else {
        if (hashTable[h2(key)][0] == key){
            return;
        }
        tmp = hashTable[h2(key)][0];
        hashTable[h2(key)][0] = key;
        hash_insert(hashTable, tmp);
    }
}

int main() {

    int n;
    cin >> n;

    string buf[3][n];

    vector<vector<long long>> student1(m), student2(m), student3(m);

    string tmp;
    long long key;
    for (int j = 0; j < 3; ++j){
        for(int i = 0; i < n; ++i){


            cin >> tmp;
            key = h(tmp);
            buf[j][i] = tmp;
            if (j == 0){

                hash_insert(student1, key);
            }
            if (j == 1){

                hash_insert(student2, key);
            }
            if (j == 2){

                hash_insert(student3, key);
            }
        }
    }

    int counter[3] {0, 0 ,0};
    int localcounter = 0;
    for (int j = 0; j < 3; ++j){
        for(int i = 0; i < n; ++i) {

            tmp = buf[j][i];
            key = h(tmp);

            if (j == 0){
                if ((student2[h1(key)].size()==1 && student2[h1(key)][0] == key) || (student2[h2(key)].size()==1 && student2[h2(key)][0] == key)){
                    localcounter += 1;
                }
                if ((student3[h1(key)].size()==1 && student3[h1(key)][0] == key) || (student3[h2(key)].size()==1 && student3[h2(key)][0] == key)){
                    localcounter += 1;
                }
                if (localcounter == 0) {counter[j]+=3;}
                if (localcounter == 1) {counter[j]+=1;}
                localcounter = 0;
            }
            if (j == 1){
                if ((student1[h1(key)].size()==1 && student1[h1(key)][0] == key) || (student1[h2(key)].size()==1 && student1[h2(key)][0] == key)){
                    localcounter += 1;
                }
                if ((student3[h1(key)].size()==1 && student3[h1(key)][0] == key) || (student3[h2(key)].size()==1 && student3[h2(key)][0] == key)){
                    localcounter += 1;
                }
                if (localcounter == 0) {counter[j]+=3;}
                if (localcounter == 1) {counter[j]+=1;}
                localcounter = 0;
            }
            if (j == 2){
                if ((student2[h1(key)].size()==1 && student2[h1(key)][0] == key) || (student2[h2(key)].size()==1 && student2[h2(key)][0] == key)){
                    localcounter += 1;
                }
                if ((student1[h1(key)].size()==1 && student1[h1(key)][0] == key) || (student1[h2(key)].size()==1 && student1[h2(key)][0] == key)){
                    localcounter += 1;
                }
                if (localcounter == 0) {counter[j]+=3;}
                if (localcounter == 1) {counter[j]+=1;}
                localcounter = 0;
            }
        }
    }

    cout << counter[0] << " " << counter[1] << " " << counter[2];


    return 0;
}