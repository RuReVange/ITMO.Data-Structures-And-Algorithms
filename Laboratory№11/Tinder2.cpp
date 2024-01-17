#include <iostream>
#include <vector>
#include <set>
using namespace std;

void make_set (int v, int* parent, int* size) {
    parent[v] = v;
    size[v] = 1;
}

int find_set (int v, int* parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v], parent);
}

void union_sets (int a, int b, int* parent, int* size) {
    a = find_set (a, parent);
    b = find_set (b, parent);
    if (a != b) {
        if (size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        } else {
            parent[b] = a;
            size[a] += size[b];
        }

    }
}


int main() {

    int n, m, q;
    cin >> n >> m >> q;

    int edge1, edge2;
    int parent[n+1];
    int size[n+1];

    for (int i = 1; i < n+1; ++i){
        make_set(i, parent, size);
    }

    int edgeG[m][2];
    set <pair <int,int>> start_edges;
    for (int i = 0; i < m; ++i){
        cin >> edge1 >> edge2;
        edgeG[i][0] = edge1;
        edgeG[i][1] = edge2;
        start_edges.insert({edge1, edge2});
    }

    char requests[q];
    int requstsEdge[q][2];
    char tmp;
    int counter = 0;
    for (int i = 0; i < q; ++i){
        cin >> requests[i] >> requstsEdge[i][0] >> requstsEdge[i][1];
        if (requests[i] == '-'){
            counter++;
            start_edges.erase({requstsEdge[i][0], requstsEdge[i][1]});
            start_edges.erase({requstsEdge[i][1], requstsEdge[i][0]});
        }
    }

    for (pair <int,int> n : start_edges){
        union_sets(n.first, n.second, parent, size);
    }

    bool result[q-counter];
    int temp = q-counter;
    counter = q - counter - 1;
    for (int i = q-1; i >=0; --i){
        if (requests[i] == '?'){
            if (find_set(requstsEdge[i][0], parent) == find_set(requstsEdge[i][1], parent)){
                result[counter] = true;
                counter--;
            }
            else {
                result[counter] = false;
                counter--;
            }
        }
        if (requests[i] == '-'){
            union_sets(requstsEdge[i][0], requstsEdge[i][1], parent, size);
        }
    }

    for (int i = 0; i < temp; ++i){
        if (result[i] == 1){
            cout << "YES" << endl;
        }
        if (result[i] == 0){
            cout << "NO" << endl;
        }
    }

    return 0;
}