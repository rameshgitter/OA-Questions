long long computeCalibrationCost(int n, int b) {
    std::vector<int> dist(n + 1, -1);
    std::queue<int> q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Operation 1: +1
        if (u + 1 <= n && dist[u + 1] == -1) {
            dist[u + 1] = dist[u] + 1;
            q.push(u + 1);
        }

        // Operation 2: -1
        if (u - 1 >= 1 && dist[u - 1] == -1) {
            dist[u - 1] = dist[u] + 1;
            q.push(u - 1);
        }

        // Operation 3: *b
        if ((long long)u * b <= n && dist[u * b] == -1) {
            dist[u * b] = dist[u] + 1;
            q.push(u * b);
        }
    }

    long long totalCost = 0;
    for (int i = 2; i <= n; ++i) {
        totalCost += dist[i];
    }

    return totalCost;
}
