#include <iostream>
using namespace std;

int main() {
    int n, m, difference;
    cin >> n >> m >> difference;
    int matrixAdjacency[n+1][n+1];
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n; ++j){
            matrixAdjacency[i][j] = 1000000;
        }
    }
    int vertex1, vertex2, weight;
    for (int i = 0; i < m; ++i){
        cin >> vertex1 >> vertex2 >> weight;
        matrixAdjacency[vertex1][vertex2] = weight;
    }

    int through_k;
    for (int k = 1; k < n+1; ++k){
        for (int i = 1; i < n+1; ++i){
            for (int j = 1; j < n+1; ++j){
                through_k = matrixAdjacency[i][k]+matrixAdjacency[k][j];
                if (through_k < matrixAdjacency[i][j] && abs(i-k)<=difference && abs(j-k)<=difference) {
                    matrixAdjacency[i][j] = through_k;
                }
            }
        }
    }

    int requests;
    cin >> requests;
    for (int i = 0; i < requests; ++i){
        cin >> vertex1 >> vertex2;
        if (matrixAdjacency[vertex1][vertex2] == 1000000){
            cout << -1 << endl;
        }
        else {
            cout << matrixAdjacency[vertex1][vertex2] << endl;
        }
    }

    return 0;
}
