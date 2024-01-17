#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

struct vertex{
    string color;
    int parent;
};

int flag = 0;

void dfs(struct vertex* arr, int v, std::vector<std::vector<int>>& listAdjacent){
    arr[v].color = "grey";
    for (int k = 0; k < listAdjacent[v].size() && flag == 0; ++k){
        int u = listAdjacent[v][k];
        if (arr[u].color == "white" && flag == 0){
            arr[u].parent = v;
            dfs(arr, u, listAdjacent);
        }
        if (arr[u].color == "grey" && flag == 0 && arr[v].parent != u){
            flag = 1;
        }
    }
    arr[v].color = "black";
}


int main() {

    int n, m;
    cin >> n >> m;
    vector <vector <int> > listAdjacent(n+1);
    int edge1, edge2;
    int counter = 0;

    for (int i = 0; i < m; ++i){
        cin >> edge1 >> edge2;
        listAdjacent[edge1].push_back(edge2);
        listAdjacent[edge2].push_back(edge1);
    }

    struct vertex arrVertex[n+1];

    for (int i = 1; i < n+1; ++i){
        arrVertex[i].color = "white";
        arrVertex[i].parent = -1;
    }

    for (int i = 1; i <= n; ++i){
        dfs(arrVertex, i, listAdjacent);
    }

    flag == 1 ? cout << "YES" : cout << "NO";

    return 0;
}