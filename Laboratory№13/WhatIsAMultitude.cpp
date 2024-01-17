#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;

    int tmp;
    vector <vector <int>> hashTable (10);
    for (int i = 0; i < n*2; ++i){
        cin >> tmp;
        hashTable[tmp%10].push_back(tmp);
    }
    for (int i = 0; i < hashTable.size(); ++i){
        if (hashTable[i].size()%2!=0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}