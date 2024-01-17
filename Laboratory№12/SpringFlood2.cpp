#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
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
    a = find_set(a, parent);
    b = find_set(b, parent);
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

bool comp(pair<pair<int,int >, int> a, pair<pair<int,int >, int> b){
    return a.second < b.second;
}

int main() {

    int n, m;
    cin >> n >> m;
    long globalWeight{};

    int edge1, edge2, weight;
    int parent[n+1];
    int size[n+1];

    for (int i = 1; i < n+1; ++i){
        make_set(i, parent, size);
    }

    vector<pair<pair <int,int>, int>> start_edges;
    for (int i = 0; i < m; ++i){
        cin >> edge1 >> edge2 >> weight;
        start_edges.push_back({{edge1, edge2}, weight});
    }

    sort(start_edges.begin(), start_edges.end(), comp);

    for (pair<pair <int,int>, int> n : start_edges){
        if (parent[n.first.first] != parent[n.first.second]) {
            globalWeight += n.second;
            union_sets(n.first.first, n.first.second, parent, size);
        }
    }

    cout << globalWeight;

    return 0;
}