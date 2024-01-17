#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

int find_set (int& v, vector<int>& parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v], parent);
}

void union_sets (int& a, int& b, vector<int>& parent, vector<int>& size) {
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

void MST_tree(vector<vector<int>>& listAdjacency, int& v, vector<int>& parent, vector<bool>& used, vector<int>& depth) {
    for (int& u : listAdjacency[v]) {
        if (!used[u]) {
            used[u] = true;
            parent[u] = v;
            depth[u] = depth[v] + 1;
            MST_tree(listAdjacency, u, parent, used, depth);
        }
    }
}

int get_max(vector<int>& depth, vector<int>& parent, int& a, int& b, map<pair<int, int>, int>& mapEdges) {
    pair<int, int> curr_ans { -1, -1 };

    while (a != b) {
        if (depth[a] > depth[b]) {
            if (curr_ans.first == -1 && curr_ans.second == -1 || mapEdges[curr_ans] < mapEdges[{ min(a, parent[a]), max(a, parent[a]) }]) {
                curr_ans = { min(a, parent[a]), max(a, parent[a]) };
            }
            a = parent[a];
        } else {
            if (curr_ans.first == -1 && curr_ans.second == -1 || mapEdges[curr_ans] < mapEdges[{ min(b, parent[b]), max(b, parent[b]) }]) {
                curr_ans = { min(b, parent[b]), max(b, parent[b]) };
            }
            b = parent[b];
        }
    }
    return mapEdges[curr_ans];
}

bool comp(pair<pair<int,int >, int>& a, pair<pair<int,int >, int>& b){
    return a.second < b.second;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int globalWeight{};

    int edge1, edge2, weight;
    vector<int> parent(n+1);
    for (int i = 1; i < n + 1; ++i) {
        parent[i] = i;
    }
    vector<int> size(n+1, 1);

    vector<pair<pair<int, int>, int>> start_edges(m);
    vector<pair<pair<int, int>, int>> requests(m);
    for (int i = 0; i < m; ++i) {
        cin >> edge1 >> edge2 >> weight;

        start_edges[i] = {{edge1, edge2}, weight};
        requests[i] = {{edge1, edge2}, weight};
    }

    sort(start_edges.begin(), start_edges.end(), comp);

    vector<vector<int>> listAdjacency(n+1);
    map<pair<int, int>, int> mapEdges;

    for (pair<pair<int, int>, int>& q: start_edges) {
        if (find_set(q.first.first, parent) != find_set(q.first.second, parent)) {
            union_sets(q.first.first, q.first.second, parent, size);
            globalWeight += q.second;
            listAdjacency[q.first.first].emplace_back(q.first.second);
            listAdjacency[q.first.second].emplace_back(q.first.first);
            mapEdges[{min(q.first.first, q.first.second), max(q.first.first, q.first.second)}] = q.second;
        }
    }

    parent[1] = 1;
    vector<bool> used (n+1, false);
    used[1] = true;
    vector<int> depth(n+1);
    depth[1] = 0;
    int root = 1;

    MST_tree(listAdjacency,root, parent, used, depth);

    for (auto& requestEdge : requests) {
        int ed = get_max(depth, parent, requestEdge.first.first, requestEdge.first.second, mapEdges);
        cout << globalWeight + requestEdge.second - ed << '\n';
    }

    return 0;
}