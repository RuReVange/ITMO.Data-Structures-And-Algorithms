#include <iostream>
#include <vector>
using namespace std;

int findPath(vector<vector<pair<int, int>>>& matrixAdjacency, vector<bool>& visited, int u, int t, int f) {
    if (u == t)
        return f;
    visited[u] = true;
    for (int v = 0; v < matrixAdjacency[u].size(); ++v) {
        if (!visited[matrixAdjacency[u][v].first] && matrixAdjacency[u][v].second > 0) {
            int df = findPath(matrixAdjacency, visited, matrixAdjacency[u][v].first, t, min(f, matrixAdjacency[u][v].second));
            if (df > 0) {
                matrixAdjacency[u][v].second -= df;
                for (int j = 0; j < matrixAdjacency[matrixAdjacency[u][v].first].size(); j++) {
                    if (matrixAdjacency[matrixAdjacency[u][v].first][j].first == u)
                    matrixAdjacency[matrixAdjacency[u][v].first][j].second += df;
                }
                return df;
            }
        }
    }
    return 0;
}

int maxFlow(vector<vector<pair<int, int>>>& matrixAdjacency, int s, int t) {
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

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    int vertex1, vertex2;
    cin >> n >> m;

    int arr[n+1][m+1];
    for (int i = 0; i < n+1; ++i){
        for (int j = 0; j < m+1; ++j){
            if (i%2 == 0) {
                if (j % 2 == 0)
                    arr[i][j] = 0;
                if (j % 2 == 1)
                    arr[i][j] = 1;
            }
            else {
                if (j % 2 == 0)
                    arr[i][j] = 1;
                if (j % 2 == 1)
                    arr[i][j] = 0;
            }
            arr[0][j] = -1;
            arr[i][0] = -1;
        }
    }

    int blackGaps;
    cin >> blackGaps;
    for (int i = 0; i < blackGaps; ++i){
        cin >> vertex1 >> vertex2;
        arr[vertex1][vertex2] = -1;
    }

    vector<int> firstPart;
    vector<int> secondPart;

    vector<vector<pair<int, int>>> matrixAdjacency(n*m+2);

    for (int i = 1; i < n+1; ++i){
        for (int j = 1; j < m+1; ++j){
            if (arr[i][j] == 0){
                firstPart.push_back((i-1)*m+j);
                if (i-1 > 0 && arr[i-1][j] == 1)
                {
                    matrixAdjacency[(i-1)*m+j].push_back({(i-1-1)*m+j, 1});
                    matrixAdjacency[(i-1-1)*m+j].push_back({(i-1)*m+j, 0});
                }
                if (i+1 < n+1 && arr[i+1][j] == 1)
                {
                    matrixAdjacency[(i-1)*m+j].push_back({(i-1+1)*m+j, 1});
                    matrixAdjacency[(i-1+1)*m+j].push_back({(i-1)*m+j, 0});
                }
                if (j-1 > 0 && arr[i][j-1] == 1)
                {
                    matrixAdjacency[(i-1)*m+j].push_back({(i-1)*m+(j-1), 1});
                    matrixAdjacency[(i-1)*m+(j-1)].push_back({(i-1)*m+j, 0});
                }
                if (j+1 < m+1 && arr[i][j+1] == 1)
                {
                    matrixAdjacency[(i-1)*m+j].push_back({(i-1)*m+(j+1), 1});
                    matrixAdjacency[(i-1)*m+(j+1)].push_back({(i-1)*m+j, 0});
                }
            }
            if (arr[i][j] == 1){
                secondPart.push_back((i-1)*m+j);
            }
        }
    }

    for (int k : firstPart){
        matrixAdjacency[0].push_back({k, 1});
    }
    for (int k : secondPart){
        matrixAdjacency[k].push_back({n*m+1, 1});
    }

    cout << maxFlow(matrixAdjacency, 0, n*m+1)*2;
    return 0;
}