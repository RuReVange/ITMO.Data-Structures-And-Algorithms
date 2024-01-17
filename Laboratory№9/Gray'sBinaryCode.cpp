#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t;
    int power = (int)(pow(2.0, (double)n));
    int arrGrey[power+1][n+1] {};
    arrGrey[1][n] = 0;
    arrGrey[2][n] = 1;
    int p = 2;
    for (int i = 2; i <= n; ++i){
        t = p;
        p *= 2;
        for (int k = (p/2 + 1); k <= p; ++k){
            for (int j = 1; j <= n; ++j){
                arrGrey[k][j] = arrGrey[t][j];
            }
            arrGrey[t][n+1-i] = 0;
            arrGrey[k][n+1-i] = 1;
            t--;
        }
    }

    for (int i = 1; i<=power; ++i){
        for (int j = 1; j <= n; ++j){
            cout << arrGrey[i][j];
        }
        cout << '\n';
    }


    return 0;
}
