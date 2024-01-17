#include <iostream>
#include <vector>
using namespace std;

struct element{
    int counter = 0;
};

int main() {

    int n;
    cin >> n;

    int tmp;
    long result = 0;
    vector <struct element> hashTable (20000002);
    for (int i = 0; i < n; ++i){
        cin >> tmp;
        if (i > tmp){
            result+=hashTable[abs(tmp - i) + 10000000].counter;
            hashTable[abs(tmp - i) + 10000000].counter+=1;
        }
        else {
            result+=hashTable[abs(tmp - i)].counter;
            hashTable[tmp - i].counter+=1;
        }
    }
    cout << result << endl;

    return 0;
}