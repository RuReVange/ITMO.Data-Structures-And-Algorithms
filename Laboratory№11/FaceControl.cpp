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

    int quantity, k;
    cin >> quantity >> k;
    int n, m;
    int vertex1, vertex2, weight;
    int tmp;
    for (int q = 0; q < quantity; ++q){
        cin >> n >> m;
        Edge edgeList[m];
        for (int i = 0; i < m; ++i){
            cin >> vertex1 >> vertex2 >> weight;
            if (i == 0){
                tmp = vertex1;
            }
            edgeList[i].start = vertex1;
            edgeList[i].end = vertex2;
            edgeList[i].weight = weight;
        }

        Vertex arrVertex[n+1];
        arrVertex[tmp].distance = 0;
        int flagRelaxation = 0;
        for (int cycle = 1; cycle < n; ++cycle){
            for (int i = 0; i < m; ++i){
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
        int flag = 0;
        for (int i = 0; i < m; ++i){
            vertex1 = edgeList[i].start;
            vertex2 = edgeList[i].end;
            weight = edgeList[i].weight;
            if (arrVertex[vertex2].distance > arrVertex[vertex1].distance + weight){
                int curParent = vertex2;
                for (int j = 0; j < n; j++){
                    curParent = arrVertex[curParent].parent;
                }
                tmp = arrVertex[curParent].parent;
                int counter = 1;
                while (tmp != curParent){
                    tmp = arrVertex[tmp].parent;
                    counter++;
                }
                if (counter > k){
                    flag = 1;
                }
            }
        }
        if (flag == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        flag = 0;
    }
    return 0;
}
