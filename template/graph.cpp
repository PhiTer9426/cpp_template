#include <bits/stdc++.h>
using namespace std;

void floyd () {
    int n = 1e5;

    long long inf = 0x3f3f3f3f3f3f3f3f;
    long long d[n][n];
    memset(d, 0x3f, sizeof d);
    for(int i=0; i<n; i++) d[i][i] = 0;
    
    vector<vector<int>> edges;
    for(int i=0; i<edges.size(); i++) {
        d[edges[i][0]][edges[i][1]] = min(d[edges[i][0]][edges[i][1]], (long long)edges[i][2]);
    }
    for (int k = 0; k < n; k ++ )
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int INF = 1e9;

void Dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();

    vector<int> distance(n, INF); // 保存起点到每个节点的距离
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

}