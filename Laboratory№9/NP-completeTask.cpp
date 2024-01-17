#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

struct vertex{
    char color;
    int parent;
};

int counter = 0;
int flag = 0;

void dfs(struct vertex* arr, int v, int n, std::vector<std::vector<int>>& listAdjacent){
    arr[v].color = 'g';
    for (int k = 0; k < listAdjacent[v].size() && flag == 0; ++k){
        int u = listAdjacent[v][k];
        if (arr[u].color == 'w'){
            arr[u].parent = v;
            dfs(arr, u, n, listAdjacent);
        }
    }
    arr[v].color = 'b';
    counter++;
    flag = 1;
}


int main() {

    int n, m;
    cin >> n >> m;
    vector <vector <int> > listAdjacent(n+1);
    int edge1, edge2;

    for (int i = 0; i < m; ++i){
        cin >> edge1 >> edge2;
        listAdjacent[edge1].push_back(edge2);
        listAdjacent[edge2].push_back(edge1);
    }

    struct vertex arrVertex[n+1];

    for (int i = 1; i < n+1; ++i){
        arrVertex[i].color = 'w';
        arrVertex[i].parent = -1;
    }

    int startVertex = -1;
    for (int i = 1; i < n+1; ++i){
        if (listAdjacent[i].size() == 1){
            startVertex = i;
            break;
        }
    }
    if (startVertex == -1){
        cout << "NO";
        return 0;
    }
    else {
        if (arrVertex[startVertex].color == 'w') {
            dfs(arrVertex, startVertex, n, listAdjacent);
        }
        (counter == n) ? cout << "YES" : cout << "NO";
    }
    return 0;
}

