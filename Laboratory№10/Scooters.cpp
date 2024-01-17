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
};

vector<int> arrTopSortReverse;
int globalComponent = 1;

void dfsTopSort(struct vertex* arr, int v, std::vector<std::vector<int>>& listAdjacent){
    arr[v].color = "grey";
    for (int k = 0; k < listAdjacent[v].size(); ++k){
        int u = listAdjacent[v][k];
        if (arr[u].color == "white"){
            arr[u].parent = v;
            dfsTopSort(arr, u, listAdjacent);
        }
    }
    arr[v].color = "black";
    arrTopSortReverse.push_back(v);
}

void dfsPowerComponent(struct vertex* arr, int* arrTopSort, int v, std::vector<std::vector<int>>& listAdjacentInvert){
    arr[v].numberComponent = globalComponent;
    for (int k = 0; k < listAdjacentInvert[v].size(); ++k){
        int u = listAdjacentInvert[v][k];
        if (arr[u].numberComponent == -1){
            dfsPowerComponent(arr, arrTopSort, u, listAdjacentInvert);
        }
    }
}


int main() {

    int n, m, q;
    cin >> n >> m >> q;
    vector <vector <int> > listAdjacent(n+1);
    vector <vector <int> > listAdjacentReverse(n+1);

    int edge1, edge2;

    for (int i = 0; i < m; ++i){
        cin >> edge1 >> edge2;
        listAdjacent[edge1].push_back(edge2);
        listAdjacentReverse[edge2].push_back(edge1);
    }

    struct vertex arrVertex[n+1];

    for (int i = 1; i < n+1; ++i){
        arrVertex[i].color = "white";
        arrVertex[i].parent = -1;
        arrVertex[i].numberComponent = -1;
    }

    for (int i = 1; i <= n; ++i){
        if (arrVertex[i].color == "white") {
            dfsTopSort(arrVertex, i, listAdjacent);
        }
    }
    int arrTopSort[n];
    for (int i = arrTopSortReverse.size()-1; i>=0; --i){
        arrTopSort[n-i-1] = arrTopSortReverse[i];
    }

    for (int i = 1; i < n+1; ++i){
        arrVertex[i].color = "white";
        arrVertex[i].parent = -1;
        arrVertex[i].numberComponent = -1;
    }

    for (int i = 0; i< n; ++i){
        if (arrVertex[arrTopSort[i]].numberComponent == -1){
            dfsPowerComponent(arrVertex, arrTopSort, arrTopSort[i], listAdjacentReverse);
            globalComponent++;
        }
    }

    for (int i = 0; i < q; ++i ){
        cin >> edge1 >> edge2;
        if (arrVertex[edge1].numberComponent == arrVertex[edge2].numberComponent){
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << '\n';
        }
    }



    return 0;
}
