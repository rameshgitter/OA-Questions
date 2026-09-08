#include <bits/stdc++.h>
using namespace std;

long long findSecondShortestTime(int n, int m, vector<vector<int>> arr) {
    // Adjacency list: u -> {v, weight}
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u = arr[i][0];
        int v = arr[i][1];
        long long w = arr[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    const long long INF = 4e18; // Sufficiently large infinity for long long
    vector<long long> dist1(n + 1, INF);
    vector<long long> dist2(n + 1, INF);

    // Min-priority queue storing pairs of {distance, station}
    priority_queue<pair<long long, int>, 
                   vector<pair<long long, int>>, 
                   greater<pair<long long, int>>> pq;

    dist1[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // If distance is strictly worse than the 2nd shortest distance to u, skip
        if (d > dist2[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;
            long long next_d = d + w;

            // Found a new shortest path to v
            if (next_d < dist1[v]) {
                dist2[v] = dist1[v];
                dist1[v] = next_d;
                pq.push({dist1[v], v});
                if (dist2[v] != INF) {
                    pq.push({dist2[v], v});
                }
            } 
            // Found a path strictly between shortest and second-shortest
            else if (next_d > dist1[v] && next_d < dist2[v]) {
                dist2[v] = next_d;
                pq.push({dist2[v], v});
            }
        }
    }

    return dist2[n];
}
