#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int matrixAdjacency[n+1][n+1];
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n; ++j){
            matrixAdjacency[i][j] = 100000;
            if (i == j){
                matrixAdjacency[i][j] = 0;
            }
        }
    }
    int vertex1, vertex2, weight;
    for (int i = 0; i < m; ++i){
        cin >> vertex1 >> vertex2 >> weight;
        matrixAdjacency[vertex1][vertex2] = weight;
        matrixAdjacency[vertex2][vertex1] = weight;
    }

    int through_k;
    for (int k = 1; k < n+1; ++k){
        for (int i = 1; i < n+1; ++i){
            for (int j = 1; j < n+1; ++j){
                through_k = matrixAdjacency[i][k]+matrixAdjacency[k][j];
                if (through_k < matrixAdjacency[i][j]) {
                    matrixAdjacency[i][j] = through_k;
                }
            }
        }
    }

    int max = 0;
    for(int i = 0; i < n+1; ++i){
        for (int j = 0; j < n+1; ++j){
            if (matrixAdjacency[i][j] > max && matrixAdjacency[i][j] != 100000){
                max = matrixAdjacency[i][j];
            }
        }
    }
    cout << max;

    return 0;
}