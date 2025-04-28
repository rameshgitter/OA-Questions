/* There was a graph given i need to tell whether its possible to traverse the graph such that i travel at each edge only once. */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Perform DFS to count reachable vertices with non-zero degree
void dfs(int src, const vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> st;
    st.push(src);
    visited[src] = true;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;  // number of vertices and edges
    vector<vector<int>> adj(V);
    vector<int> degree(V, 0);

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;      // zero-based vertex indices
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++; degree[v]++;
    }

    // Find a vertex with non-zero degree to start DFS
    int start = -1;
    for (int i = 0; i < V; ++i) {
        if (degree[i] > 0) {
            start = i;
            break;
        }
    }
    // If no edges, trivially Eulerian
    if (start == -1) {
        cout << "Yes\n";
        return 0;
    }

    // Check connectivity of non-zero-degree vertices
    vector<bool> visited(V, false);
    dfs(start, adj, visited);
    for (int i = 0; i < V; ++i) {
        if (degree[i] > 0 && !visited[i]) {
            cout << "No\n";
            return 0;
        }
    }

    // Count vertices with odd degree
    int oddCount = 0;
    for (int d : degree)
        if (d % 2 != 0)
            oddCount++;

    // Decide based on oddCount
    if (oddCount == 0 || oddCount == 2)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
