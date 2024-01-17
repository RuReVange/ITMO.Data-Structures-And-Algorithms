#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <list>
using namespace std;

struct vertex{
    char color = 'w';
    int distance = 10000000;
    int parent = -1;
};

vector<int> result;

void dfs(struct vertex* arr, int v, int n, int** matrixAdjacency){
    arr[v].color = 'g';
    for (int k = 1; k < n+1; ++k){
        if (matrixAdjacency[v][k] != 10000000) {
            int u = k;
            if (arr[u].color == 'w') {
                dfs(arr, u, n, matrixAdjacency);
            }
        }
    }
    arr[v].color = 'b';
    result.push_back(v);
}


int main() {

    int n, m;
    cin >> n >> m;

    int start, end;
    cin >> start >> end;

    int** matrixAdjacency;
    matrixAdjacency = new int* [n+1];
    for (int i = 0; i < n+1; ++i){
        matrixAdjacency[i] = new int[n+1];
    }

    for (int i = 0; i< n+1; ++i){
        for (int j = 0; j < n+1; ++j){
            matrixAdjacency[i][j] = 10000000;
        }
    }

    int vertex1, vertex2, weight;
    for (int i = 0; i < m; ++i){
        cin >> vertex1 >> vertex2 >> weight;
        matrixAdjacency[vertex1][vertex2] = weight;
    }

    struct vertex arrVertex[n+1];

    for (int i = 1; i <= n; ++i){
        if (arrVertex[i].color == 'w') {
            dfs(arrVertex, i, n, matrixAdjacency);
        }
    }
    int arrResult[n];
    for (int i = result.size() - 1; i>=0; --i){
        arrResult[n-1-i] = result[i];
    }
    int u;
    int flag = 0;
    arrVertex[start].distance = 0;
    for (int i = 0; i < n; ++i){
        u = arrResult[i];
        if (start == u){
            flag = 1;
            for (int v = 1; v < n+1; ++v){
                if (matrixAdjacency[u][v] != 10000000){
                    if (arrVertex[v].distance > arrVertex[u].distance + matrixAdjacency[u][v]){
                        arrVertex[v].distance = arrVertex[u].distance + matrixAdjacency[u][v];
                        arrVertex[v].parent = u;
                    }
                }
            }
        }
        if (flag == 1){
            for (int v = 1; v < n+1; ++v){
                if (matrixAdjacency[u][v] != 10000000){
                    if (arrVertex[v].distance > arrVertex[u].distance + matrixAdjacency[u][v]){
                        arrVertex[v].distance = arrVertex[u].distance + matrixAdjacency[u][v];
                        arrVertex[v].parent = u;
                    }
                }
            }
        }
    }
    if (arrVertex[end].distance != 10000000){
        cout << arrVertex[end].distance;
    }
    else {
        cout << -1;
    }

    return 0;
}
