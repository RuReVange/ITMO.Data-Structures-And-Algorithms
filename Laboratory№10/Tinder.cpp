#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <list>
using namespace std;

struct vertex{
    char color;
    int numberComponent;
};

int globalComponent = 1;

void dfs(struct vertex* arr, int v, std::vector<std::vector<int>>& listAdjacent){
    arr[v].color = 'g';
    arr[v].numberComponent = globalComponent;
    for (int k = 0; k < listAdjacent[v].size(); ++k){
        int u = listAdjacent[v][k];
        if (arr[u].color == 'w'){
            dfs(arr, u, listAdjacent);
        }
    }
    arr[v].color = 'b';
}


int main() {

    int n, m, q;
    cin >> n >> m >> q;
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
        arrVertex[i].numberComponent = -1;
    }

    for (int i = 1; i <= n; ++i){
        if (arrVertex[i].color == 'w') {
            dfs(arrVertex, i, listAdjacent);
            globalComponent++;
        }
    }

    char tmp;
    for (int i = 0; i < q; ++i){
        globalComponent = 1;
        cin >> tmp;
        if (tmp == '?'){
            cin >> edge1 >> edge2;
            if (arrVertex[edge1].numberComponent == arrVertex[edge2].numberComponent){
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        if (tmp == '-'){
            cin >> edge1 >> edge2;
            erase(listAdjacent[edge1], edge2);
            erase(listAdjacent[edge2], edge1);

            for (int i = 1; i < n+1; ++i){
                arrVertex[i].color = 'w';
                arrVertex[i].numberComponent = -1;
            }

            for (int i = 1; i <= n; ++i){
                if (arrVertex[i].color == 'w') {
                    dfs(arrVertex, i, listAdjacent);
                    globalComponent++;
                }
            }

        }
    }

    return 0;
}