#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct vertex{
    char color;
    int distance;
};

void bfs(struct vertex* arr, int start, int n, vector <vector <int> > &listAdjacent){
    for (int i = 1; i < n+1; ++i){
        arr[i].color = 'w';
        arr[i].distance = -1;
    }
    arr[start].color = 'g';
    arr[start].distance = 0;
    list<int> queue;
    queue.push_back(start);
    while (queue.empty() != true){
        int u = queue.front();
        queue.pop_front();
        for (int k = 0; k < listAdjacent[u].size(); ++k){
            int v = listAdjacent[u][k];
            if (arr[v].color == 'w'){
                arr[v].color = 'g';
                arr[v].distance = arr[u].distance + 1;
                queue.push_back(v);
            }
        }
        arr[u].color = 'b';
    }
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

    int start, end;
    cin >> start >> end;

    struct vertex arr[n+1];
    bfs(arr,start, n, listAdjacent);

    cout << arr[end].distance;


    return 0;
}
