#include <iostream>
#include <vector>
using namespace std;

int findPath(int** matrixAdjacency, vector<bool>& visited, int u, int t, int f) {
    if (u == t)
        return f;
    visited[u] = true;
    for (int v = 1; v < t+1; ++v) {
        if (!visited[v] && matrixAdjacency[u][v] > 0) {
            int df = findPath(matrixAdjacency, visited, v, t, min(f, matrixAdjacency[u][v]));
            if (df > 0) {
                matrixAdjacency[u][v] -= df;
                matrixAdjacency[v][u] += df;
                return df;
            }
        }
    }
    return 0;
}

int maxFlow(int** matrixAdjacency, int s, int t) {
    int flow = 0;
    while (true) {
        vector<bool> visited(t+1);
        int df = findPath(matrixAdjacency, visited, s, t, 1000000);
        if (df == 0)
            return flow;
        flow += df;
    }
}

int main() {
    int n, m, weight;
    int vertex1, vertex2;
    cin >> n >> m;

    int** matrixAdjacency;
    matrixAdjacency = new int* [n+1];
    for (int i = 0; i < n+1; ++i){
        matrixAdjacency[i] = new int[n+1];
    }

    for (int i = 0; i < n+1; ++i){
        for (int j = 0; j < n+1; ++j){
            matrixAdjacency[i][j] = 0;
        }
    }

    for (int i = 0; i < m; ++i){
        cin >> vertex1 >> vertex2 >> weight;
        matrixAdjacency[vertex1][vertex2] = weight;
    }

    cout << maxFlow(matrixAdjacency, 1, n);
    //cout << ans;
    return 0;
}
