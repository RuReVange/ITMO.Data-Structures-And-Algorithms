#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <list>
using namespace std;

struct vertex{
    string color;
    int parent;
    int position;
};

vector<int> result;

void dfs(struct vertex* arr, int v, std::vector<std::vector<int>>& listAdjacent, int& n){
    arr[v].color = "grey";
    for (int k = 0; k < listAdjacent[v].size(); ++k){
        int u = listAdjacent[v][k];
        if (arr[u].color == "white"){
            arr[u].parent = v;
            dfs(arr, u, listAdjacent, n);
        }
    }
    arr[v].color = "black";
    arr[v].position = n;
    n--;
}


int main() {

    int n, m;
    cin >> n >> m;
    vector <vector <int> > listAdjacent(n+1);
    int edge1, edge2;
    int counter = n;

    for (int i = 0; i < m; ++i){
        cin >> edge1 >> edge2;
        listAdjacent[edge1].push_back(edge2);
    }

    struct vertex arrVertex[n+1];

    for (int i = 1; i < n+1; ++i){
        arrVertex[i].color = "white";
        arrVertex[i].parent = -1;
    }

    for (int i = 1; i <= n; ++i){
        if (arrVertex[i].color == "white") {
            dfs(arrVertex, i, listAdjacent, counter);
        }
    }

    for (int i = 1; i < n+1; ++i){
        cout << arrVertex[i].position << ' ';
    }

    return 0;
}
