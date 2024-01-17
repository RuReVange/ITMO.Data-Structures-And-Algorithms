#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void buildPrefixFunction(int* pattern, vector<int>& pi, int& n) {
    int i = 1; int j = 0;
    while (i < n){
        if (pattern[i] == pattern[j]){
            pi[i+1] = j+1;
            ++i; ++j;
        }
        else {
            if (j>0) { j = pi[j];}
            else { pi[i+1] = 0; ++i;}
        }
    }
}

int main() {

    int numcard, maxnum;
    cin >> numcard >> maxnum;

    int arr[numcard];
    for (int i = 0; i < numcard; ++i) {
        cin >> arr[i];
    }
    int flag = 0;
    for (int i = numcard/2; i >= 0; --i) {
        flag = 0;
        for (int j = 0; j < i; ++j) {
            if (arr[i-j-1] != arr[i+j]){
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            cout << (numcard-i) << ' ';
        }
    }

    return 0;
}