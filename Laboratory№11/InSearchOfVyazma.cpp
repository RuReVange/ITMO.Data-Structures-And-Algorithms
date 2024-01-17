#include <iostream>
using namespace std;

struct Edge{
    int start;
    int end;
    int weight;
};

struct Vertex{
    int distance = 10000000;
    int parent = -1;
};

int main() {

    int n, m, q, start;
    int vertex1, vertex2, weight;

    cin >> n >> m >> q >> start;
    Edge edgeList[2*m];
    for (int i = 0; i < m; ++i){
        cin >> vertex1 >> vertex2 >> weight;
        edgeList[i].start = vertex1;
        edgeList[i].end = vertex2;
        edgeList[i].weight = weight;
        edgeList[(2*m-1)-i].start = vertex2;
        edgeList[(2*m-1)-i].end = vertex1;
        edgeList[(2*m-1)-i].weight = weight;
    }

    Vertex arrVertex[n+1];
    arrVertex[start].distance = 0;
    int flagRelaxation = 0;
    for (int cycle = 1; cycle < n; ++cycle){
        for (int i = 0; i < 2*m; ++i){
            vertex1 = edgeList[i].start;
            vertex2 = edgeList[i].end;
            weight = edgeList[i].weight;
            if (arrVertex[vertex2].distance > arrVertex[vertex1].distance + weight){
                flagRelaxation = 1;
                arrVertex[vertex2].distance = arrVertex[vertex1].distance + weight;
                arrVertex[vertex2].parent = vertex1;
            }
        }
        if (flagRelaxation == 0){
            break;
        }
        flagRelaxation = 0;
    }

    int tmp;
    for (int i = 0; i < q; ++i){
        cin >> tmp;
        if (arrVertex[tmp].distance != 10000000){
            cout << arrVertex[tmp].distance << endl;
        }
        else {
            cout << -1 << endl;
        }
    }

    return 0;
}