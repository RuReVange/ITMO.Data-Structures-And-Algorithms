#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <list>
using namespace std;

struct vertex{
    string color;
    int parent;
    int numberComponent;
    int existTrap;
};

int globalComponent = 1;

void dfs(struct vertex* arr, int v, int* arrtrap, std::vector<std::vector<int>>& listAdjacent){
    arr[v].color = "grey";
    arr[v].numberComponent = globalComponent;
    if (arr[v].existTrap == 1){
        arrtrap[globalComponent] = 1;
    }
    for (int k = 0; k < listAdjacent[v].size(); ++k){
        int u = listAdjacent[v][k];
        if (arr[u].color == "white"){
            arr[u].parent = v;
            dfs(arr, u, arrtrap, listAdjacent);
        }
    }
    arr[v].color = "black";
}


int main() {

    int n, m, t;
    cin >> n >> m;
    vector <vector <int> > listAdjacent(n+1);

    int edge1, edge2;

    for (int i = 0; i < m; ++i){
        cin >> edge1 >> edge2;
        listAdjacent[edge1].push_back(edge2);
        listAdjacent[edge2].push_back(edge1);
    }

    struct vertex arrVertex[n+1];
    int arrTrap[n+1];

    for (int i = 1; i < n+1; ++i){
        cin >> t;
        arrVertex[i].color = "white";
        arrVertex[i].parent = -1;
        arrVertex[i].numberComponent = -1;
        arrVertex[i].existTrap = t;
        arrTrap[i] = 0;
    }

    for (int i = 1; i <= n; ++i){
        if (arrVertex[i].color == "white") {
            dfs(arrVertex, i, arrTrap, listAdjacent);
            globalComponent++;
        }
    }

    cout << globalComponent - 1 << endl;
    for (int i = 1; i < n+1; ++i){
        cout << arrVertex[i].numberComponent << " ";
    }
    cout << endl;
    for (int i = 1; i< globalComponent; ++i){
        cout << arrTrap[i] << " ";
    }

    return 0;
}
