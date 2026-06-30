#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
typedef long long ll;

struct Edge {
    int to; 
    ll weight;
};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<vector<Edge>> adj(n + 1);

    // 1. Add regular roads
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // 2. Add magical bridges as weight 0 edges
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        // Magical bridges take 0 time and are bidirectional
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 0});
    }

    // 3. Standard Dijkstra from city 1 to city N
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
    }

    return 0;
}
